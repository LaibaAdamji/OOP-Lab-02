#include <iostream>
using namespace std;

class Car {
private:

    mutable int engine_horsepower;
    mutable int seating_capacity;
    mutable int no_of_speakers;

public:

    Car(int hp, int seats, int speakers)
        : engine_horsepower(hp), seating_capacity(seats), no_of_speakers(speakers) {}


    void modifyAttributes(int hp, int seats, int speakers) const {
        cout << "Modifying attributes via a constant function hehe?..." << endl;
        engine_horsepower = hp;
        seating_capacity = seats;
        no_of_speakers = speakers;
    }


    void displayDetails() const {
        cout << "Car Details:" << endl;
        cout << "Engine Horsepower: " << engine_horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }
};


int main() {

    Car aaaaa(150, 5, 4);


    cout << "Initial Car Details:" << endl;
    aaaaa.displayDetails();

    aaaaa.modifyAttributes(200, 7, 6);

    cout << "\nUpdated Car Details: :((" << endl;
    aaaaa.displayDetails();

    return 0;
}
