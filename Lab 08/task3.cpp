#include <iostream>
#include <string>

class Person {
protected:
    int employeeID;

public:
    void getData(int id) {
        employeeID = id;
    }

    void displayData() const {
        std::cout << "Employee ID: " << employeeID << std::endl;
    }
};

class Admin : public Person {
private:
    std::string name;
    double monthlyIncome;

public:
    void getData(int id, const std::string& n, double income) {
        Person::getData(id);
        name = n;
        monthlyIncome = income;
    }

    void displayData() const {
        Person::displayData();
        std::cout << "Name: " << name << std::endl;
        std::cout << "Monthly Income: " << monthlyIncome << std::endl;
        std::cout << "Bonus: " << bonus() << std::endl;
    }

    double bonus() const {
        return monthlyIncome * 12 * 0.05;
    }
};

class Accounts : public Person {
private:
    std::string name;
    double monthlyIncome;

public:
    void getData(int id, const std::string& n, double income) {
        Person::getData(id);
        name = n;
        monthlyIncome = income;
    }

    void displayData() const {
        Person::displayData();
        std::cout << "Name: " << name << std::endl;
        std::cout << "Monthly Income: " << monthlyIncome << std::endl;
        std::cout << "Bonus: " << bonus() << std::endl;
    }

    double bonus() const {
        return monthlyIncome * 12 * 0.05;
    }
};