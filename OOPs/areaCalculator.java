import java.util.*;

class areaCalculator {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Area Calculator");
        System.out.println("Choose a shape to calculate the area:");
        System.out.println("1. Circle");
        System.out.println("2. Square");
        System.out.println("3. Rectangle");
        System.out.println("4. Triangle");
        
        int choice = sc.nextInt();
        
        switch (choice) {
            case 1:
                // Area of Circle
                System.out.print("Enter the radius of the circle: ");
                double radius = sc.nextDouble();
                double areaCircle = Math.PI * radius * radius;
                System.out.println("The area of the circle is: " + areaCircle);
                break;
                
            case 2:
                // Area of Square
                System.out.print("Enter the side length of the square: ");
                double side = sc.nextDouble();
                double areaSquare = side * side;
                System.out.println("The area of the square is: " + areaSquare);
                break;
                
            case 3:
                // Area of Rectangle
                System.out.print("Enter the length of the rectangle: ");
                double length = sc.nextDouble();
                System.out.print("Enter the width of the rectangle: ");
                double width = sc.nextDouble();
                double areaRectangle = length * width;
                System.out.println("The area of the rectangle is: " + areaRectangle);
                break;
                
            case 4:
                // Area of Triangle
                System.out.print("Enter the base of the triangle: ");
                double base = sc.nextDouble();
                System.out.print("Enter the height of the triangle: ");
                double height = sc.nextDouble();
                double areaTriangle = 0.5 * base * height;
                System.out.println("The area of the triangle is: " + areaTriangle);
                break;
                
            default:
                System.out.println("Invalid choice. Please choose a valid shape.");
        }
        
        sc.close();
    }
}
