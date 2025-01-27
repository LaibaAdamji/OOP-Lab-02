#include<iostream>
using namespace std;

int main(){
    int num, i, total = 0;
    cout<<"No. of elements: ";
    cin>>num;
    int *elements = new int[num];
    for (i = 0; i < num; i++) {
        cout<<"Enter element: " << i + 1 << ": ";
        cin>>elements[i];
    }
    for (i = 0; i < num; i++) {
        total += *(elements + i);
    }
    cout<<"Sum: " << total;
    delete[] elements;
    return 0;
}
