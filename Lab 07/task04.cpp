#include <iostream>
#include <vector>
using namespace std;

class Person {
    public:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;

    Person(string name, int id, string address, string phoneNumber, string email) : name(name), id(id), address(address), phoneNumber(phoneNumber), email(email) {};

    virtual void updateInfo() {
        cout << "Enter new name: ";
        cin >> name;
        cout << "Enter new id: ";
        cin >> id;
        cout << "Enter new address: ";
        cin >> address;
        cout << "Enter new phone number: ";
        cin >> phoneNumber;
        cout << "Enter new email: ";
        cin >> email;
    }

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};

class Student : public Person {
    public:
    vector <string> coursesEnrolled;
    double GPA;
    int enrollmentYear;

    Student(vector <string> courses, double g, int year, string n, int stdId, string add, string pNum, string email) : Person(n, stdId, add, pNum, email) {
        coursesEnrolled = courses;
        GPA = g;
        enrollmentYear = year;
    }

    void updateInfo() override {
        Person::updateInfo();
        cout << "Enter new GPA: ";
        cin >> GPA;
        cout << "Enter new enrollment year: ";
        cin >> enrollmentYear;
        cout << "Enter number of courses enrolled: ";
        int numCourses;
        cin >> numCourses;
        vector<string> newCourses;
        for (int i = 0; i < numCourses; i++) {
            cout << "Enter course " << i + 1 << ": ";
            string course;
            cin >> course;
            newCourses.push_back(course);
        }
        coursesEnrolled = newCourses;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << GPA;
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "Courses Enrolled: ";
        for (const auto& course : coursesEnrolled) {
            cout << course << " ";
        }   
    }
};

class Professor : public Person {
    public:
    vector <string> coursesTaught;
    double salary;
    string department;

    Professor(vector <string> cTaught, double sal, string dept, string n, int stdId, string add, string pNum, string email) : Person(n, stdId, add, pNum, email) {
        coursesTaught = cTaught;
        salary = sal;
        department = dept;
    }

    void updateInfo() override {
        Person::updateInfo();
        cout << "Enter new salary: ";
        cin >> salary;
        cout << "Enter new department: ";
        cin >> department;
        cout << "Enter number of courses to add: ";
        int numCourses;
        cin >> numCourses;
        vector<string> newCourses;
        for (int i = 0; i < numCourses; i++) {
            cout << "Enter course " << i + 1 << ": ";
            string course;
            cin >> course;
            newCourses.push_back(course);
        }
        coursesTaught.insert(newCourses.end(), newCourses.begin(), newCourses.end());
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
        cout << "Courses Taught: ";
        for (const auto& course : coursesTaught) {
            cout << course << " ";
        }
    }
};

class Staff : public Person {
    public:
    double salary;
    string position;
    string department;

    Staff(string name, int id, string address, string phoneNumber, string email, double sal, string pos, string dept) : Person(name, id, address, phoneNumber, email) {
        salary = sal;
        position = pos;
        department = dept;
    }
    
    void displayInfo() override {
        Person::displayInfo();
        cout << "Salary: " << salary << endl;
        cout << "Position: " << position << endl;
        cout << "Department: " << department << endl;
    }

};

int main() {
    vector<Person*> universityMembers;

    vector<string> studentCourses = {"Math", "Science", "English"};
    Student student(studentCourses, 3.5, 2018, "John Doe", 12345, "123 Main St", "123-456-7890", "johndoe@example.com");
    universityMembers.push_back(&student);


    vector<string> professorCourses = {"Math", "Science"};
    Professor professor(professorCourses, 80000, "Mathematics", "Jane Smith", 67890, "456 Elm St", "987-654-3210", "janesmith@example.com");
    universityMembers.push_back(&professor);

    Staff staff("Bob Johnson", 11111, "789 Oak St", "555-123-4567", "bobjohnson@example.com", 60000, "Janitor", "Facilities");
    universityMembers.push_back(&staff);

    for (const auto& member : universityMembers) {
        member->displayInfo();
        cout << endl;
    }

    student.updateInfo();

    cout << "Updated Student Information:" << endl;
    student.displayInfo();

    return 0;
}
