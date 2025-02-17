#include <iostream>
#include <string>
using namespace std; 

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    //constructor
    Invoice(const string& number, const string& description, int qty, double price)
        : partNumber(number), partDescription(description), quantity(qty > 0 ? qty : 0), pricePerItem(price > 0 ? price : 0.0) {}
    //copy constructor
    Invoice(const Invoice& other)
        : partNumber(other.partNumber), partDescription(other.partDescription), quantity(other.quantity), pricePerItem(other.pricePerItem) {}
    //copy assignment operator
    Invoice& operator=(const Invoice& other) {
        if (this != &other) {
            partNumber = other.partNumber;
            partDescription = other.partDescription;
            quantity = other.quantity;
            pricePerItem = other.pricePerItem;
        }
        return *this;
    }

    //move constructor
    Invoice(Invoice&& other) noexcept
        : partNumber(move(other.partNumber)), partDescription(move(other.partDescription)), quantity(other.quantity), pricePerItem(other.pricePerItem) {
        other.quantity = 0;
        other.pricePerItem = 0.0;
    }
    //move assignment operator
    Invoice& operator=(Invoice&& other) noexcept {
        if (this != &other) {
            partNumber = move(other.partNumber);
            partDescription = move(other.partDescription);
            quantity = other.quantity;
            pricePerItem = other.pricePerItem;
            other.quantity = 0;
            other.pricePerItem = 0.0;
        }
        return *this;
    }

    //calc invoice amount
    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }

     //destructor
    ~Invoice() {
        cout << "Invoice object destroyed." << endl;
    }

    //ggetters
    string getPartNumber() const {return partNumber; }
    string getPartDescription() const { return partDescription;}
    int getQuantity() const { return quantity; }
    double getPricePerItem() const {return pricePerItem; }
};

int main() {
    Invoice inv1("1234", "funny hammer", 2, 14.95);
    cout << "Invoice Amount: " << inv1.getInvoiceAmount() << endl;

    Invoice inv2 = inv1; //copy constructor
    cout << "Copied Invoice Amount: " << inv2.getInvoiceAmount() << endl;

    Invoice inv3("5678", "nmails polish", 5, 0.99);
    inv3 = inv1; // Copy assignment
    cout << "Assigned Invoice Amount: " << inv3.getInvoiceAmount() << endl;

    return 0;
}
