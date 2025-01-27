#include<iostream>
using namespace std;

int main(){
    float wKg, wLb;
    cout << "Enter weight in kilograms: ";
    cin >> wKg;
    wLb = wKg * 2.2;
    cout << "Weight in kilograms: " << wKg << endl;
    cout << "Weight in pounds: " << wLb << endl;
    return 0;
}
