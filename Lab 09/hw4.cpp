#include <iostream>
#using namespace std; 

class Student {
public:
    virtual double getTuition(const string& status, int creditHours) const = 0;
    virtual ~Student() = default;
};

class GraduateStudent : public Student {
    string researchTopic;
public:
    void setResearchTopic(const string& topic) { researchTopic = topic; }
    string getResearchTopic() const { return researchTopic; }
    
    double getTuition(const string& status, int creditHours) const override {
        if (status == "undergraduate") return 200 * creditHours;
        if (status == "graduate") return 300 * creditHours;
        if (status == "doctoral") return 400 * creditHours;
        return 0;
    }
};

int main() {
    GraduateStudent gs;
    gs.setResearchTopic("Machine Learning");
    cout << "Graduate tuition: " << gs.getTuition("graduate", 12) << endl;
    return 0;
}
