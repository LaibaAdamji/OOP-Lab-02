#include <iostream>
#include <vector> // :(((( we really could've existed without this library as humanity. yk. we didn't need vectors. just yeah.

using namespace std;

class Car {
private:
    string name;
    int id;

public:
    //constructor
    Car(string carName, int carId) : name(carName),id(carId) {}

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }
};

class Garage {
private:
    vector<Car*> cars; 

public:
    void parkCar(Car* car) {
        cars.push_back(car);
        cout << "Car parked: " << car->getName()<< " (ID: " << car->getId() << ")" << endl;
    }

    void listCars() const {
        if (cars.empty()) {
            cout << "No cars parked in the garage." << endl;
        } else {
            cout << "Cars parked in the garage:" << endl;
            for (const auto& car : cars) {
                cout << " - " << car->getName() << " (ID: " << car->getId() << ")" << endl;
            }
        }
    }
};

int main() {
    Car car1("Toyototoa", 1);
    Car car2("Haha", 2);
    Car car3("Fun stuff hehe", 3);

    Garage garage;

    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);

    garage.listCars();

    cout << "End of main() func. Cars will be destroyed. haw :(" << endl;

    return 0;
}

