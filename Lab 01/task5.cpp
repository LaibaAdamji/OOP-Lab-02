#include<iostream>
using namespace std;

int main(){
    string movie;
    float adultPrice, childPrice; // ticket prices
    int cTickets, aTickets, totalSold; // num tickets
    float donatePercent;
    float grossRev, donationAmount, netRev;

    cout << "Enter movie name: ";
    getline(cin, movie);
    cout << "Enter adult ticket price: ";
    cin >> adultPrice;
    cout << "Enter child ticket price: ";
    cin >> childPrice;
    cout << "Enter adult tickets sold: ";
    cin >> aTickets;
    cout << "Enter child tickets sold: ";
    cin >> cTickets;
    cout << "Enter percentage to be donated: ";
    cin >> donatePercent;

    totalSold = aTickets + cTickets;
    grossRev = (aTickets * adultPrice) + (cTickets * childPrice);
    donationAmount = (donatePercent / 100) * grossRev;
    netRev = grossRev - donationAmount;

    cout << "Movie name: " << movie;
    cout << "\nNumber of tickets sold: " << totalSold;
    cout << "\nGross amount: $" << grossRev;
    cout << "\nPercentage of gross amount donated: " << donatePercent << "%";
    cout << "\nAmount donated: $" << donationAmount;
    cout << "\nNet sale: $" << netRev;

    return 0;
}
