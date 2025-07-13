//1.1.10. Calculate area of various shapes



public double area(double length, double breadth) {
if (length <= 0 || breadth <= 0) {
throw new IllegalArgumentException("Length and breadth must be greater than zero.");
}
return length * breadth;
}
public double area(double radius) {
if (radius <= 0) {
throw new IllegalArgumentException("Radius must be greater than zero.");
}
return 3.14 * radius * radius;
}
public static void main(String[] args) {
CalculateArea calculator = new CalculateArea();
Scanner scanner = new Scanner(System.in);
System.out.print("Length: ");
double length = scanner.nextDouble();
System.out.print("Width: ");
double width = scanner.nextDouble();
try {
double rectangleArea = calculator.area(length, width);
System.out.println("Area of the rectangle: " + String.format("%.2f", rectangleArea));
} catch (IllegalArgumentException e) {
System.out.println(e.getMessage());
}
System.out.print("Radius: ");
double radius = scanner.nextDouble();
try {
double circleArea = calculator.area(radius);
System.out.println("Area of the circle: " + String.format("%.2f", circleArea));
} catch (IllegalArgumentException e) {
System.out.println(e.getMessage());
}
scanner.close();
}
}
