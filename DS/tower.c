#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Stack structure
typedef struct Stack {
    int *items;
    int top;
    int capacity;
} Stack;

// Create a stack of given capacity
Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Push an item to the stack
void push(Stack *stack, int item) {
    stack->items[++stack->top] = item;
}

// Pop an item from the stack
int pop(Stack *stack) {
    return stack->items[stack->top--];
}

// Move disk between two poles
void moveDisk(char from, char to, int disk) {
    printf("Move disk %d from rod %c to rod %c\n", disk, from, to);
}

// Perform the moves between the rods
void moveBetweenPoles(Stack *src, Stack *dest, char s, char d) {
    int srcTop = isEmpty(src) ? INT_MAX : pop(src);
    int destTop = isEmpty(dest) ? INT_MAX : pop(dest);

    if (srcTop > destTop) {
        push(src, srcTop);
        push(src, destTop);
        moveDisk(d, s, destTop);
    } else {
        push(dest, destTop);
        push(dest, srcTop);
        moveDisk(s, d, srcTop);
    }
}

// Implement Tower of Hanoi using stacks
void towerOfHanoi(int num_of_disks, Stack *src, Stack *aux, Stack *dest) {
    int total_moves = (1 << num_of_disks) - 1;
    char s = 'A', d = 'C', a = 'B';

    // Push disks onto source rod
    for (int i = num_of_disks; i >= 1; i--) {
        push(src, i);
    }

    // If number of disks is even, swap destination and auxiliary rods
    if (num_of_disks % 2 == 0) {
        char temp = d;
        d = a;
        a = temp;
    }

    // Perform the moves
    for (int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1) {
            moveBetweenPoles(src, dest, s, d);
        } else if (i % 3 == 2) {
            moveBetweenPoles(src, aux, s, a);
        } else if (i % 3 == 0) {
            moveBetweenPoles(aux, dest, a, d);
        }
    }
}

int main() {
    int num_of_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_of_disks);

    Stack *src = createStack(num_of_disks);
    Stack *aux = createStack(num_of_disks);
    Stack *dest = createStack(num_of_disks);

    towerOfHanoi(num_of_disks, src, aux, dest);

    free(src->items);
    free(src);
    free(aux->items);
    free(aux);
    free(dest->items);
    free(dest);

    return 0;
}
