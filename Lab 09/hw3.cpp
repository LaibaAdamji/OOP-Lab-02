#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    double salary;
public:
    virtual void getdata() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }
    virtual void displaydata() {
        cout << "Name: " << name << "\nSalary: " << salary << endl;
    }
    virtual double bonus() = 0;
    virtual ~Person() = default;
};

class Account : public Person {
public:
    double bonus() override { return salary * 0.1; }
};

class Admin : public Person {
public:
    double bonus() override { return salary * 0.15; }
};

class Master : public Account, public Admin {
public:
    void getdata() override { Account::getdata(); }
    void displaydata() override { Account::displaydata(); }
    double bonus() override { return Account::bonus() + Admin::bonus(); }
};

int main() {
    Master emp;
    emp.getdata();
    emp.displaydata();
    cout << "Bonus: " << emp.bonus() << endl;
    return 0;
}
