#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Employee {
protected:
    int id;
    string name;

public:
    Employee(int empId, string empName): id(empId), name(empName) {}

    virtual void displayInfo() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};


class IOrderTaker {
public:
    virtual void takeOrder(const string& order) = 0;
};


class IOrderPreparer {
public:
    virtual void prepareOrder(const string& order) =0;
};


class IBiller {
public:
    virtual void generateBill(const string& order) = 0;
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int empId, string empName) : Employee(empId, empName) {}

    void takeOrder(const string& order) override {
        cout << "Waiter " << name << " is taking order: " << order << endl;
    }
};


class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, string empName) : Employee(empId, empName) {}

    void prepareOrder(const string& order) override {
        cout << "Chef " << name << " is preparing order: " << order << endl;
    }
};


class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, string empName) : Employee(empId, empName) {}

    void generateBill(const string& order) override {
        cout << "Cashier " << name << " is generating bill for order: " << order << endl;
    }
};


class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int empId, string empName) : Employee(empId, empName){}

    void takeOrder(const string& order) override {
        cout << "Manager " << name << "is taking order: "<< order << endl;
    }

    void generateBill(const string& order) override {
        cout << "Manager " << name << " is generating bill for order: " << order << endl;
    }
};


class Menu {
protected:
    vector<string> items;
    vector<double> prices;

public:
    virtual double calculateTotal() const = 0; 


    void addItem(const string& item, double price) {
        items.push_back(item);
        prices.push_back(price);
    }

    void displayMenu() const {
        cout << "Menu:" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << items[i] << " - $" << prices[i] << endl;
        }
    }
};

// FoodMenu class
class FoodMenu : public Menu {
public:
    double calculateTotal() const override {
        double total = 0.0;
        for (double price : prices) {
            total += price;
        }
        return total;
    }
};


class BeverageMenu : public Menu {
private:
    const double beverageTax = 0.1; // 10% tax on bevs

public:
    double calculateTotal() const override {
        double total = 0.0;
        for (double price : prices) {
            total += price * (1 + beverageTax); //tax appl.
        }
        return total;
    }
};


int main() {

    Waiter waiter(1, "John");
    Chef chef(2, "Alice");
    Cashier cashier(3, "Bob");
    Manager manager(4, "Eve");


    FoodMenu foodMenu;
    foodMenu.addItem("Burger", 8.99);
    foodMenu.addItem("Pizza", 12.99);

    BeverageMenu beverageMenu;
    beverageMenu.addItem("Soda", 2.50);
    beverageMenu.addItem("Coffee", 3.00);

    // Display menus
    cout << "Food Menu:" << endl;
    foodMenu.displayMenu();
    cout << "Total cost: $" << foodMenu.calculateTotal() << endl;

    cout << "\nBeverage Menu:" << endl;
    beverageMenu.displayMenu();
    cout << "Total cost: $" << beverageMenu.calculateTotal() << endl;

    cout << "\nTaking orders: (" << endl;
    waiter.takeOrder("Burger and Soda");
    manager.takeOrder("Pizza and Coffee");

    cout << "\nPreparing orders:" << endl;
    chef.prepareOrder("Burger and Soda");

    cout << "\nGenerating bills:" << endl;
    cashier.generateBill("Burger and Soda");
    manager.generateBill("Pizza and Coffee");


    vector<Employee*> employees = {&waiter, &chef, &cashier, &manager};
    cout << "\nEmployee Information:" << endl;
    for (const auto& emp : employees) {
        emp->displayInfo();
    }

    return 0;
}
