#include <iostream>
using namespace std;

class User{
    public:
        int Age;
        string Name;
};

void main(){
    User obj;
    obj.Name = "Teo";
    obj.Age = 24;

    cout << "My name is " << obj.Name << " and I'm " << obj.Age << " years old.";
}
