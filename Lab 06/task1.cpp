//static const dma, has-a rel agrregation composition association inheritance(bg qs 8 wtg), move copy constructor rule of 5 and 3 - also from lab 6


#include <iostream>
using namespace std;

class BankAccount {

    public:
        int accNum;
        float balance;
        bool check;

        BankAccount(){}

        BankAccount(int aNum, float bal) : accNum(aNum) , balance(bal) {}       

        void deposit(float num) {
            balance += num;
            check = true;
        }

        int withdraw(float num) {
            if (num > balance) {
                cout << "Invalid Withdraw amount.";
                return 0;
            } else {
                balance -= num;
                cout << "Amount withdrawn.";
                return 1;
            }
        }
};

class SavingsAccount: public BankAccount {

    public:
        float interestMonthly;

        SavingsAccount(float intM) : interestMonthly(intM) {}

        void ApplyInterest(int numMonths) {
            balance -= (interestMonthly * numMonths);
        }
};

class CheckingAccount : public BankAccount {

    public:

        double overdraftLimit;
        double loan;

        CheckingAccount(double odLim) : overdraftLimit(odLim) {}

        void overDraft(float num){
            if (withdraw(num) == 0) {
                loan = num - (balance + overdraftLimit);
                if (loan > 0) {
                    cout << "Overdraft limit exceeded.";
                }
            }
        }
};

class BusinessAccount : public BankAccount {

    public:
        double coporateTax;

        BusinessAccount(double ct) : coporateTax(ct) {}

        void ApplycorpTax() {
            if(check == true) {
                balance -= coporateTax;
            }
        }
};


class Employee {
    public:
    string name;
    int id;
    float salary;
    double taxRate;
    double taxPaid;
};

class Customer: public BankAccount {
    public:
    string name;
    int bankID;

    Customer(string n , int bID) : name(n), bankID(bID) {}
};

class Teller: private BankAccount, public Employee {

    public:
    bool freeze; 
    void freezeAccount() {
        freeze = true;        
    }
};

class Manager: public BankAccount, public Employee {

};
