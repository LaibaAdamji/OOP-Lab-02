#include<iostream>
using namespace std;

class Currency { //base
    public:

    double amount;
    int currencyCode;
    string currencySymbol;
    double exchangeRate;

    Currency(double a, int cCode, string symbol, double eRate) : amount(a), currencyCode(cCode), currencySymbol(symbol), exchangeRate(eRate) {};

    double convertToBase() {
        return amount * exchangeRate;
    }

    virtual double convertTo(Currency &obj) {
        return (amount * exchangeRate) / obj.exchangeRate;
    }

    virtual void displayCurrency() {
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Currency Symbol: " << currencySymbol << endl;
    }
};

class Dollar : public Currency {
    public:
    Dollar(double a, int cCode, string symbol, double eRate) : Currency(a,cCode, symbol, eRate) {};
    
    double convertTo(Currency &obj) override {
        return (amount * exchangeRate) / obj.exchangeRate;
    }

    void displayCurrency() override {
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Currency Symbol: " << currencyCode << endl;
    }

};

class Euro : public Currency {
    public:
    Euro(double a, int cCode, string symbol, double eRate) : Currency(a, cCode, symbol, eRate) {};

    double convertTo(Currency &obj) override {
        return (amount * exchangeRate) / obj.exchangeRate;
    }

    void displayCurrency() override {
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Currency Symbol: " << currencySymbol << endl;
    }

};

class Rupee : public Currency {
    public:
    Rupee(double a, int cCode, string symbol, double eRate) : Currency(a, cCode, symbol, eRate) {};

    double convertTo(Currency &obj) override {
        return (amount * exchangeRate) / obj.exchangeRate;
    }

    void displayCurrency() override {
        cout << "Currency Code: " << currencyCode << endl;
    }
};

int main() {
    Dollar dollar(100, 1, "$", 1.0);
    Euro euro(100, 2, "€", 0.88);
    Rupee rupee(100, 3, "R", 0.013);

    cout << "Dollar Information:" << endl;
    dollar.displayCurrency();
    cout << endl;

    cout << "Euro Information:" << endl;
    euro.displayCurrency();
    cout << endl;

    cout << "Rupee Information:" << endl;
    rupee.displayCurrency();
    cout << endl;

    cout << "Converting 100 Dollars to Euros: " << dollar.convertTo(euro) << endl;
    cout << "Converting 100 Euros to Rupees: " << euro.convertTo(rupee) << endl;
    cout << "Converting 100 Rupees to Dollars: " << rupee.convertTo(dollar) << endl;

    return 0;
}