#include<iostream>
#include<vector>
using namespace std;

class Account{ //base class

    public:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
    vector <double> balanceArray{};

    Account(){};
    Account(int aNum,double bal,string aName,string aType): accountNumber(aNum), balance(bal), accountHolderName(aName), accountType(aType) {}//constructor
    void deposit(double amount){balance += amount;}
    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            balanceArray.push_back();
            } 
        else {
            cout << "insufficient balance";}
    }
    void calculateInterest(){
        double interest = balance * 0.05;
        balance += interest;
    }
    void printStatement(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;

    }
    void display(){
        cout << "Account Number: " << accountNumber << endl << "Account Holder Name: " << accountHolderName << endl << "Account Type: " << accountType << endl << "Balance: " << balance << endl;
    }
};
