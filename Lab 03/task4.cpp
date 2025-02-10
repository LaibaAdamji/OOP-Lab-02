#include <iostream>
#include <string>
#include <cstdlib>

class Employee {
private:
    std::string firstName;
    std::string lastName;
    double monthlySalary;

public:
    Employee(std::string fName, std::string lName, double salary) {
        firstName = fName;
        lastName = lName;
        monthlySalary = (salary > 0) ? salary : 0.0;
    }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    double getMonthlySalary() const { return monthlySalary; }
    double getYearlySalary() const { return monthlySalary * 12; }

    void giveRaise(double percentage) {
        monthlySalary += monthlySalary * (percentage / 100);
    }
};

int main(int argc, char *argv[]) {
    if (argc != 7) {
        std::cerr << "Usage: " << argv[0] << " FirstName1 LastName1 Salary1 FirstName2 LastName2 Salary2\n";
        return 1;
    }

    Employee emp1(argv[1], argv[2], std::stod(argv[3]));
    Employee emp2(argv[4], argv[5], std::stod(argv[6]));

    std::cout << "Yearly Salaries Before Raise:\n";
    std::cout << emp1.getFirstName() << " " << emp1.getLastName() << ": $" << emp1.getYearlySalary() << "\n";
    std::cout << emp2.getFirstName() << " " << emp2.getLastName() << ": $" << emp2.getYearlySalary() << "\n";
    emp1.giveRaise(10);
    emp2.giveRaise(10);

    std::cout << "\nYearly Salaries After 10% Raise:\n";
    std::cout << emp1.getFirstName() << " " << emp1.getLastName() << ": $" << emp1.getYearlySalary() << "\n";
    std::cout << emp2.getFirstName() << " " << emp2.getLastName() << ": $" << emp2.getYearlySalary() << "\n";

    return 0;
}
