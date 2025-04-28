#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int years;
};

vector<Employee> readEmployees() {
    ifstream file("employees.txt");
    vector<Employee> employees;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Employee e;
        ss >> e.id >> e.name >> e.designation >> e.years;
        employees.push_back(e);
    }
    return employees;
}

void writeEmployees(const vector<Employee>& employees) {
    ofstream file("employees.txt");
    for (const auto& e : employees) {
        file << e.id << " " << e.name << " " << e.designation << " " << e.years << endl;
    }
}

void createDummyData() {
    ofstream file("employees.txt");
    file << "1 John Manager 3\n";
    file << "2 Alice Developer 1\n";
    file << "3 Bob Manager 2\n";
    file << "4 Carol HR 4\n";
}

int main() {
    createDummyData();
    
    auto employees = readEmployees();
    vector<Employee> managers;
    for (const auto& e : employees) {
        if (e.designation == "Manager" && e.years >= 2) {
            managers.push_back(e);
        }
    }
    
    writeEmployees(managers);
    
    for (auto& e : managers) {
        e.id += 10;
        e.years += 1;
    }
    writeEmployees(managers);
    
    return 0;
}
