class areaRecTri {
    double area;

    // Constructor for rectangle
    areaRecTri(int length, int width) {
        area = length * width;
    }

    // Constructor for triangle
    areaRecTri(double base, double height) {
        area = 0.5 * base * height;
    }

    void displayArea() {
        System.out.println("Area: " + area);
    }

    public static void main(String[] args) {
        // Calculate area of rectangle
        areaRecTri rectangle = new areaRecTri(5, 4);
        rectangle.displayArea();

        // Calculate area of triangle
        areaRecTri triangle = new areaRecTri(5.0, 4.0);
        triangle.displayArea();
    }
}
