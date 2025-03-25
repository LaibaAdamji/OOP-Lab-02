#include<iostream>
#include <vector>
using namespace std;

class BigInteger {
    private:
    vector<int> digits;
    bool sign; // true for positive, false for negative

    public:

    BigInteger(vector <int> dig, bool s) : digits(dig), sign(s) {}

    BigInteger operator +(const BigInteger &other) {
        if (sign == other.sign) {
            int maxLen = max(digits.size(), other.digits.size());
            vector<int> result(maxLen, 0);
            int carry = 0;
            for (int i = 0; i < maxLen; i++) {
                int sum = (i < digits.size() ? digits[i] : 0) + (i < other.digits.size() ? other.digits[i] : 0) + carry;
                    result[i] = sum % 10;
                    carry = sum / 10;
            }
        }
        else {
            if (sign == true) {
                return BigInteger(other.digits, other.sign) - BigInteger(other.digits, other.sign);
            }
            else {
                return BigInteger(digits, sign) - BigInteger(digits, sign);
            }
        }
    }




};