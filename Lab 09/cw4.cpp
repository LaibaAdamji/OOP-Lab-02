#include <iostream>
#include <string>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;

public:
    Flight(string num, string dep, string arr, int cap): flightNumber(num), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    bool bookSeat() {
        if (bookedSeats >= capacity) return false;
        bookedSeats++;
        return true;
    }

    bool cancelSeat() {
        if (bookedSeats <= 0) return false;
        bookedSeats--;
        return true;
    }

    bool upgradeSeat() {
        return true; // Simplified for example
    }

    int getAvailableSeats() const { return capacity - bookedSeats; }
};

class Passenger {
private:
    string id;
    string name;

public:
    Passenger(string i, string n) : id(i), name(n) {}

    bool requestBooking(Flight& flight) {
        return flight.bookSeat();
    }

    bool requestCancellation(Flight& flight) {
        return flight.cancelSeat();
    }
};

int main() {
    Flight nyc("NYC101", "10:00", "12:00", 150);
    Passenger bob("P001", "Bob");
    bob.requestBooking(nyc);
    cout << "Available seats: " << nyc.getAvailableSeats() << endl;
    return 0;
}
