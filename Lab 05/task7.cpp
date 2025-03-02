#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    const int roll_no; //constant var
    string name;

public:

    Student(int r, string n) : roll_no(r), name(n) {}


    void displayDetails() const {
        cout << "Student Details:" << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
    }
};


int main() {
    int rollNo;
    string name;

    cout << "Enter Roll No: ";
    cin >> rollNo;
    cin.ignore(); 
    cout << "Enter Name: ";
    getline(cin, name);


    Student student(rollNo, name);


    student.displayDetails();

    return 0;
}
