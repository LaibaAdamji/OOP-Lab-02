#include <iostream>

class Shape {
private:
    double area;

public:
    Shape(double a = 0) : area(a) {}

    double Area() const {
        return area;
    }

    Shape operator+(const Shape& other) const {
        return Shape(area + other.area);
    }

    friend std::ostream& operator<<(std::ostream& os, const Shape& s) {
        os << s.area;
        return os;
    }
};