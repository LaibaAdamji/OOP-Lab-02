#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    double price;
public:
    Car(string m, double p) : model(m), price(p) {}
    virtual void setPrice(double p) = 0;
    string getModel() const { return model; }
    double getPrice() const { return price; }
    virtual ~Car() = default;
};

class Color : public Car {
    string color;
public:
    Color(string m, double p, string c) : Car(m, p), color(c) {}
    void setPrice(double p) override { price = p; }
    string getColor() const { return color; }
};

class Company : public Car {
    string company;
public:
    Company(string m, double p, string c) : Car(m, p), company(c) {}
    void setPrice(double p) override { price = p; }
    string getCompany() const { return company; }
};

int main() {
    Color redCar("Model S", 80000, "Red");
    redCar.setPrice(85000);
    cout << redCar.getModel() << " costs " << redCar.getPrice() << endl;
    return 0;
}
