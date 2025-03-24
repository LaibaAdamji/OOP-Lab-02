#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Shape { //base
    public:
    
    vector <int> position;
    string color;
    double borderThickness;

    Shape(vector <int> pos, string c, double bT) {
        position = pos;
        color = c;
        borderThickness = bT;
    }

    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }

    virtual double calculateArea() {
        return 0;
    }

    virtual double calculatePerimeter() {
        return 0;
    }
    
    void display(){
        cout << "Position: ";
        for(int i = 0; i < position.size(); i++){
            cout << position[i] << " ";
        }
        cout << endl;
        cout << "Color: " << color << endl;
        cout << "Border Thickness: " << borderThickness << endl;
    }
};

class Circle : public Shape { //derived
    public:
    double radius;
    vector <int> centerPosition;
    double PI = 3.14;

    Circle(double radius, vector <int> centerPosition, string color, double borderThickness) : Shape(centerPosition, color, borderThickness) {
        this->radius = radius;
    }

    void draw() override {
        cout << "Drawing a circle" << endl;
    }

    double calculateArea() override {
        return PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * PI * radius;
    }
}; 

class Rectangle : public Shape {
    public:
    double width;
    double height;
    vector <int> topLeftPosition;
    

    Rectangle(double w, double h, vector <int> topLeft, string color, double borderThickness) : Shape(topLeft, color, borderThickness) {
        this->width = w;
        this->height = h;
    }

    void draw() override {
        cout << "Drawing a rectangle" << endl;
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Polygon : public Shape {
public:
    vector<pair<int, int>> vertices;
    double PI = 3.142;
    
    Polygon(vector<pair<int, int>> v, string color, double bT) : Shape({0, 0}, color, bT) {
        this->vertices = v;
    }
    
    void draw() override {
        cout << "Drawing a polygon" << endl;
    }
    
    double calculateArea() override {
        double area = 0;
        for (int i = 0; i < vertices.size(); i++) {
            int x1 = vertices[i].first;
            int y1 = vertices[i].second;
            int x2 = vertices[(i + 1) % vertices.size()].first;
            int y2 = vertices[(i + 1) % vertices.size()].second;
            area += (x1 * y2 - x2 * y1);
        }
        return abs(area) / 2;
    }
    
    double calculatePerimeter() override {
        double perimeter = 0;
        for (int i = 0; i < vertices.size(); i++) {
            int x1 = vertices[i].first;
            int y1 = vertices[i].second;
            int x2 = vertices[(i + 1) % vertices.size()].first;
            int y2 = vertices[(i + 1) % vertices.size()].second;
            perimeter += sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        }
        return perimeter;
    }
};

int main() {

    //cirlce obj
    vector<int> circleCenter = {0, 0};
    Circle circle(5, circleCenter, "Red", 2);

    //rectangle obj
    vector<int> rectangleTopLeft = {1, 1};
    Rectangle rectangle(4, 6, rectangleTopLeft, "Blue", 1);

    //polygon obj
    vector<pair<int, int>> polygonVertices = {{0, 0}, {3, 0}, {3, 4}, {0, 4}};
    Polygon polygon(polygonVertices, "Green", 3);

    cout << "Circle:" << endl;
    circle.display();
    circle.draw();
    cout << "Area: " << circle.calculateArea() << endl;
    cout << "Perimeter: " << circle.calculatePerimeter() << endl;

    cout << "\nRectangle:" << endl;
    rectangle.display();
    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << endl;
    cout << "Perimeter: " << rectangle.calculatePerimeter() << endl;

    cout << "\nPolygon:" << endl;
    polygon.display();
    polygon.draw();
    cout << "Area: " << polygon.calculateArea() << endl;
    cout << "Perimeter: " << polygon.calculatePerimeter() << endl;

    return 0;
}
