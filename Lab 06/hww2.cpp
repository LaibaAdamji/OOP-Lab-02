#include <iostream>
#include <string>
using namespace std;


class Vehicles {
protected:
    double price;

public:
    Vehicles(double p) : price(p) {}

    virtual void displayDetails() const {
        cout << "Price: $" << price << endl;
    }
};


class Car : public Vehicles {
protected:
    int seatingCapacity;
    int numberOfDoors;
    string fuelType;

public:
    Car(double p, int seats, int doors, const string& fuel)
        : Vehicles(p), seatingCapacity(seats), numberOfDoors(doors), fuelType(fuel) {}

    void displayDetails() const {
        Vehicles::displayDetails();
        cout << "Seating Capacity: " << seatingCapacity << ", Number of Doors: " << numberOfDoors
             << ", Fuel Type: " << fuelType << endl;
    }
};

class Motorcycle : public Vehicles {
protected:
    int numberOfCylinders;
    int numberOfGears;
    int numberOfWheels;

public:
    Motorcycle(double p, int cylinders, int gears, int wheels)
        : Vehicles(p), numberOfCylinders(cylinders), numberOfGears(gears), numberOfWheels(wheels) {}

    void displayDetails() const {
        Vehicles::displayDetails();
        cout << "Number of Cylinders: " << numberOfCylinders << ", Number of Gears: " << numberOfGears
             << ", Number of Wheels: " << numberOfWheels << endl;
    }
};

// Derived class Audi (inherits from Car)
class Audi : public Car {
private:
    string modelType;

public:
    Audi(double p, int seats, int doors, const string& fuel, const string& model)
        : Car(p, seats, doors, fuel), modelType(model) {}

    void displayDetails() const {
        Car::displayDetails();
        cout << "Model Type: " << modelType << endl;
    }
};


class Yamaha : public Motorcycle {
private:
    string makeType;

public:
    Yamaha(double p, int cylinders, int gears, int wheels, const string& make)
        : Motorcycle(p, cylinders, gears, wheels), makeType(make) {}

    void displayDetails() const {
        Motorcycle::displayDetails();
        cout << "Make Type: " << makeType << endl;
    }
};


int main() {

      Audi audi(50000, 5, 4, "Petrol", "A4");
    Yamaha yamaha(10000, 2, 5, 2, "YZF-R1");


    cout << "Audi Car Details:" << endl;
    audi.displayDetails();
    cout << endl;

    cout << "Yamaha Motorcycle Details:" << endl;
    yamaha.displayDetails();

    return 0;
}
