class rectangleSimple {
    double width;
    double height;

    // Constructor to initialize width and height
    rectangleSimple(double w, double h) {
        width = w;
        height = h;
    }

    // Method to calculate the area of the rectangle
    double area() {
        return width * height;
    }

    // Method to calculate the perimeter of the rectangle
    double perimeter() {
        return 2 * (width + height);
    }

    public static void main(String[] args) {
        // Create a Rectangle object
        rectangleSimple rect = new rectangleSimple(5.0, 3.0);

        // Calculate and display the area and perimeter
        System.out.println("Area: " + rect.area());
        System.out.println("Perimeter: " + rect.perimeter());
    }
}
