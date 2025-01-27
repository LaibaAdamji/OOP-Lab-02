#include<iostream>
using namespace std;

int main(){
    int consumedUnits;
    float totalBill = 0, surcharge = 0;
    string customerName, customerID;
    
    cout << "Enter customer ID: ";
    getline(cin, customerID);
    cout << "Enter customer name: ";
    getline(cin, customerName);
    cout << "Enter units consumed: ";
    cin >> consumedUnits;

    if (consumedUnits < 0) {
        cout << "Invalid units entered";
        return 0;
    }

    cout << "Customer ID: " << customerID;
    cout << "\nCustomer name: " << customerName;
    cout << "\nUnits consumed: " << consumedUnits;

    if (consumedUnits <= 199) {
        totalBill = consumedUnits * 16.20;
        cout << "\nAmount charged @Rs 16.20 per unit: " << totalBill;
    } else if (consumedUnits >= 200 && consumedUnits < 300) {
        totalBill = consumedUnits * 20.10;
        cout << "\nAmount charged @Rs 20.10 per unit: " << totalBill;
    } else if (consumedUnits >= 300 && consumedUnits < 500) {
        totalBill = consumedUnits * 27.10;
        cout << "\nAmount charged @Rs 27.10 per unit: " << totalBill;
    } else if (consumedUnits >= 500) {
        totalBill = consumedUnits * 35.90;
        cout << "\nAmount charged @Rs 35.90 per unit: " << totalBill;
    }

    if (totalBill > 18000) {
        surcharge = totalBill * 0.15;
        totalBill += surcharge;
    }

    cout << "\nSurcharge amount: " << surcharge;
    cout << "\nNet amount paid by customer: " << totalBill;

    return 0;
}
