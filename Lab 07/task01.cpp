#include<iostream>
#include<vector>
using namespace std;

class Account{ //base class

    public:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
    vector <double> balanceHistory{};

    Account() = default;

    Account(int aNum,double bal,string aName,string aType): accountNumber(aNum), balance(bal), accountHolderName(aName), accountType(aType) {}//constructor
    void deposit(double amount){
        balance += amount;
        balanceHistory.push_back(balance);
    }
    bool withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            balanceHistory.push_back(balance);
            return true;
            } 
        else {
            cout << "insufficient balance";
            return false;}
    }
    virtual void calculateInterest(){
        double interest = balance * 0.05;
        balance += interest;
    }
    void printStatement(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
        cout << "Balance History: ";
        for(int i = 0; i < balanceHistory.size(); i++){
            cout << balanceHistory[i] << " ";  
            }
        cout << endl;
    }

    void display(){
        cout << "Account Number: " << accountNumber << endl << "Account Holder Name: " << accountHolderName << endl << "Account Type: " << accountType << endl << "Balance: " << balance << endl;
    }
};


class SavingsAccount : public Account {
    public:
    double interestRate;
    double minBalance = 100.0;
    double interest;

    SavingsAccount(int aNum,double bal,string aName,double iRate): Account(aNum,bal,aName,"Savings"), interestRate(iRate) {}
    
    void calculateInterest() override {
        if (balance >= minBalance){
            interest = balance * interestRate;
            balance += interest;
            balanceHistory.push_back(balance);
        }
        else {
            cout << "Minimum balance not met"; 
        }
    }

    void printStatement(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
        cout << "Balance History: ";
        for(int i = 0; i < balanceHistory.size(); i++){
            cout << balanceHistory[i] << " ";
        }
        cout << endl;
        cout << "Interest applied: " << interest << endl;
    }
};


class CheckingAccount : public Account {
    public:
    double overdraftLimit = 1000.0;
    double overdraftFee = 20.0;
    double overdraftBalance;
    double overdraftHistory[100];
    double amount;
    
    int overdraftHistoryIndex = 0;
    CheckingAccount(int aNum,double bal,string aName, double amm): Account(aNum,bal,aName,"Checking"), amount(amm) {}

    void withdraw(double amount){
        if (balance - amount >= -overdraftLimit){
            balance -= amount;
            balanceHistory.push_back(balance);
            if (balance < 0){
                overdraftBalance = balance;
                balanceHistory.push_back(balance);
                balance = 0;
            }
        }
        else {
            cout << "Overdraft limit exceeded";
            overdraftBalance = balance;
            balance = 0;
            balanceHistory.push_back(balance);
            overdraftHistory[overdraftHistoryIndex] = overdraftBalance;
            overdraftHistoryIndex++;
        }
    }
};

class FixedDepositAccount : public Account {
    public:
    double fixedInterestRate = 0.05;
    string maturityDate;
    double maturityBalance;
    double interest;
    double amount;

    FixedDepositAccount(int accountNumber, double initialAmount, string accountHolderName, string maturityDate, double fixedInterestRate = 0.05)
    : Account(accountNumber, initialAmount, accountHolderName, "Fixed Deposit") {
    this->amount = initialAmount;
    this->maturityDate = maturityDate;
    this->maturityBalance = initialAmount;
    this->interest = 0.0;
    this->fixedInterestRate = fixedInterestRate;
    }    

    void withdraw(double amount){
        if (balance - amount >= 0){
            balance -= amount;
            balanceHistory.push_back(balance);
        }
        else {
            cout << "Insufficient balance";
        }
    }

    void printStatement(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Maturity Balance: " << maturityBalance << endl;
    }
};

int main() {
//acc class
    Account account1(12345, 1000.0, "John Doe", "General");
    account1.deposit(500.0);
    account1.withdraw(200.0);
    account1.calculateInterest();
    account1.printStatement();

//savings class
    SavingsAccount savingsAccount1(67890, 2000.0, "Jane Doe", 0.03);
    savingsAccount1.deposit(1000.0);
    savingsAccount1.withdraw(500.0);
    savingsAccount1.calculateInterest();
    savingsAccount1.printStatement();

//checking class
    CheckingAccount checkingAccount1(34567, 1500.0, "Bob Smith", 1000.0);
    checkingAccount1.withdraw(2000.0);
    checkingAccount1.printStatement();

//fixed deposit class
    FixedDepositAccount fixedDepositAccount1(90123, 5000.0, "Alice Johnson", "2025-03-24");
    fixedDepositAccount1.withdraw(2000.0);
    fixedDepositAccount1.printStatement();

    return 0;
}

