#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

void init(Stack* s)
{
    s->top = -1;
}

int isEmpty(Stack* s)
{
    return s->top == -1;
}

int isFull(Stack* s)
{
    return s->top == MAX - 1;
}

void push(Stack* s, int item)
{
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d\n", item);
        return;
    }
    s->items[++(s->top)] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* s)
{
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void display(Stack* s)
{
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack items: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

void menu()
{
    Stack s;
    init(&s);
    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the item to push: ");
            scanf("%d", &item);
            push(&s, item);
            break;
        case 2:
            item = pop(&s);
            if (item != -1) {
                printf("Popped item: %d\n", item);
            }
            break;
        case 3:
            display(&s);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

int main()
{
    menu();
    return 0;
}
