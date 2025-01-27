#include<iostream>
using namespace std;

int main(){
    string stdName;
    float scores[5], avgScr = 0;
    int i;

    cout << "Enter student's name: ";
    getline(cin, stdName);

    for (i = 0; i < 5; i++) {
        cout << "Enter score " << i + 1 << ": ";
        cin >> scores[i];
        avgScr += scores[i];
    }

    avgScr /= 5;

    cout << "Student name: " << stdName << endl;
    for (i = 0; i < 5; i++) {
        cout << scores[i];
        if (i != 4) {
            cout << ", ";
        }
    }
    cout << "\nAverage test score: " << avgScr;

    return 0;
}
