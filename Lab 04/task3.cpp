#include <iostream>
#include <string>

class Invoice {
private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    double pricePerItem;

public:
    //constructor
    Invoice(const std::string& number, const std::string& description, int qty, double price)
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
        : partNumber(std::move(other.partNumber)), partDescription(std::move(other.partDescription)), quantity(other.quantity), pricePerItem(other.pricePerItem) {
        other.quantity = 0;
        other.pricePerItem = 0.0;
    }
    //move assignment operator
    Invoice& operator=(Invoice&& other) noexcept {
        if (this != &other) {
            partNumber = std::move(other.partNumber);
            partDescription = std::move(other.partDescription);
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
        std::cout << "Invoice object destroyed." << std::endl;
    }

    //ggetters
    std::string getPartNumber() const {return partNumber; }
    std::string getPartDescription() const { return partDescription;}
    int getQuantity() const { return quantity; }
    double getPricePerItem() const {return pricePerItem; }
};

int main() {
    Invoice inv1("1234", "funny hammer", 2, 14.95);
    std::cout << "Invoice Amount: " << inv1.getInvoiceAmount() << std::endl;

    Invoice inv2 = inv1; //copy constructor
    std::cout << "Copied Invoice Amount: " << inv2.getInvoiceAmount() << std::endl;

    Invoice inv3("5678", "nmails polish", 5, 0.99);
    inv3 = inv1; // Copy assignment
    std::cout << "Assigned Invoice Amount: " << inv3.getInvoiceAmount() << std::endl;

    return 0;
}
