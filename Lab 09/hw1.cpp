#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override { return width * height; }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea() const override { return 0.5 * base * height; }
};

int main() {
    Rectangle rect(5, 4);
    Triangle tri(5, 4);
    cout << "Rectangle area: " << rect.getArea() << endl;
    cout << "Triangle area: " << tri.getArea() << endl;
    return 0;
}
