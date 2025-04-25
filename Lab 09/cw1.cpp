#include <iostream>
#include <stdexcept>

class Wallet {
private:
    double balance;
    double dailyDeposit;
    double dailyWithdrawal;
    static constexpr double DAILY_DEPOSIT_LIMIT = 10000.0;
    static constexpr double DAILY_WITHDRAWAL_LIMIT = 5000.0;

    void resetDailyLimits() {
        dailyDeposit = 0;
        dailyWithdrawal = 0;
    }

public:
    Wallet() : balance(0), dailyDeposit(0), dailyWithdrawal(0) {}

    bool deposit(double amount) {
        if (amount <= 0) return false;
        if (dailyDeposit + amount > DAILY_DEPOSIT_LIMIT) return false;
        
        balance += amount;
        dailyDeposit += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) return false;
        if (amount > balance) return false;
        if (dailyWithdrawal + amount > DAILY_WITHDRAWAL_LIMIT) return false;
        
        balance -= amount;
        dailyWithdrawal += amount;
        return true;
    }

    double getBalance() const { return balance; }
};

class User {
private:
    std::string userID;
    std::string name;
    Wallet wallet;

public:
    User(std::string id, std::string n) : userID(id), name(n) {}
    bool deposit(double amount) { 
      return wallet.deposit(amount); }
    bool withdraw(double amount) { 
      return wallet.withdraw(amount); }
    double checkBalance() const{ 
      return wallet.getBalance(); }
};

int main() {
    User alice("A123", "Alice");
    alice.deposit(500);
    alice.withdraw(200);
    std::cout << "Alice's balance: " << alice.checkBalance() << std::endl;
    return 0;
}
