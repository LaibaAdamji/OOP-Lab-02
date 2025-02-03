#include <iostream>
#include <vector>
#include <string>

struct Subject {
    std::string subjects[3];
};

struct Student {
    int id;
    Subject subj;
};

int main() {
    int num;
    std::cout << "Enter the number of students: ";
    std::cin >> num;

    std::vector<Student> students(num); 

    for (int i = 0; i < num; i++) {
        std::cout << "Enter ID for student " << i + 1 << ": ";
        std::cin >> students[i].id;

        std::cout << "Enter 3 subjects: ";
        for (int j = 0; j < 3; j++) {
            std::cin >> students[i].subj.subjects[j];
        }
    }
    std::cout << "\nStudent Records:\n";
    for (const auto &student : students) {
        std::cout << "ID: " << student.id << "\nSubjects: ";
        for (const auto &subject : student.subj.subjects) {
            std::cout << subject << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
