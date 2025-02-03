#include <iostream>
#include <algorithm> //sorting ig (self note: do research)
#include <vector>
#include <string>

struct Person {
    int id;
    std::string name;
};

bool compID(const Person &a, const Person &b) {
    return a.id < b.id;
}
bool compName(const Person &a, const Person &b) {
    return a.name < b.name;
}

int main() {
    int num;
    std::cout << "Enter the number of persons: ";
    std::cin >> num;

    std::vector<Person> people(num);

    for (int i = 0; i < N; i++) {
        std::cout << "Enter ID and Name for person " << i + 1 << ": ";
        std::cin >> people[i].id >> people[i].name;
    }

    //by id
    std::sort(people.begin(), people.end(), compID);
    std::cout << "\nSorted by ID:\n";
    for (const auto &p : people) {
        std::cout << "ID - " << p.id << ", Name: " << p.name << std::endl;
    }
    //by name
    std::sort(people.begin(), people.end(), compName);
    std::cout << "\nSorted by Name:\n";
    for (const auto &p : people) {
        std::cout << "ID - " << p.id << ", Name: " << p.name << std::endl;
    }

    return 0;
}
