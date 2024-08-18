class Shape {
    double area;

    // Constructor for rectangle
    Shape(int length, int width) {
        area = length * width;
    }

    // Constructor for triangle
    Shape(double base, double height) {
        area = 0.5 * base * height;
    }

    void displayArea() {
        System.out.println("Area: " + area);
    }

    public static void main(String[] args) {
        // Calculate area of rectangle
        Shape rectangle = new Shape(5, 4);
        rectangle.displayArea();

        // Calculate area of triangle
        Shape triangle = new Shape(5.0, 4.0);
        triangle.displayArea();
    }
}
