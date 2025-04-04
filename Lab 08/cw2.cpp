#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PolynomialUtils;

class Polynomial {
    private:
    vector <int> coefficients;
    int numElement;

    public:
    
    Polynomial() {} 
    Polynomial(vector <int> coefficients) {
        this->coefficients = coefficients;
        numElement = coefficients.size();
    }

    Polynomial operator +(const Polynomial& obj){
        vector <int> result;
        int maxLength = max(numElement, obj.numElement);
        for (int i = 0; i < maxLength; i++) {
            int sum = 0;
            if (i < numElement) {
                sum += coefficients[i];
            }
            if (i < obj.numElement) {
                sum += obj.coefficients[i];
            }
            result.push_back(sum);
        }
        return Polynomial(result);
    }

    Polynomial operator -(const Polynomial& obj) {
        vector <int> result;
        int maxLength = max(numElement, obj.numElement);
        for (int i = 0; i < maxLength; i++) {
            int diff = 0;
            if (i < numElement) {
                diff += coefficients[i];
            }
            if (i < obj.numElement) {
                diff -= coefficients[i];
            }
            result.push_back(diff);
        }
        return Polynomial(result);
    }

    Polynomial operator *(const Polynomial& obj) {
        vector <int> result;
        for (int i = 0; i < numElement; i++) {
            for (int j = 0; j < obj.numElement; j++) {
                result.push_back(coefficients[i] * obj.coefficients[j]);
            }
        }
        return Polynomial(result);
    }

    friend ostream& operator <<(ostream &os, const Polynomial &obj) {
        for (int i = 0; i < obj.numElement; i++) {
            if (obj.coefficients[i] < 0) {
                os << " - " << abs(obj.coefficients[i]) << "x^" << i << " ";
            } else if (obj.coefficients[i] == 0) {
                continue;
            } else {
            os << obj.coefficients[i] << "x^" << obj.numElement - i - 1 << " ";        }
        }
        return os;
    }

    friend class PolynomialUtils;

};

class PolynomialUtils{
    public:

    int evaluate(const Polynomial &p, int x) {
        int result = 0;
        for (int i = 0; i < p.numElement; i++) {
            result += p.coefficients[i] * pow(x, p.numElement - i - 1);
        }
    }

    Polynomial derivative(const Polynomial &p) {
        vector <int> result;
        for (int i = 1; i < p.numElement; i++) {
            int newCoefficient = p.coefficients[i] * i;
            int newExponent = i - 1;
            result.push_back(newCoefficient);
        }

        return Polynomial(result);
    }

};

int main() {
    
    Polynomial p1({3, 2, 1}); // 1 + 2x + 3x^2
    Polynomial p2({4, 5}); // 4 + 5x

    std::cout << "Polynomial 1: " << p1 << std::endl;
    std::cout << "Polynomial 2: " << p2 << std::endl;

    Polynomial sum = p1 + p2;
    std::cout << "Sum: " << sum << std::endl;

    Polynomial difference = p1 - p2;
    std::cout << "Difference: " << difference << std::endl;

    Polynomial product = p1 * p2;
    std::cout << "Product: " << product << std::endl;

    PolynomialUtils utils;
    int evaluation = utils.evaluate(p1, 2);
    std::cout << "Evaluation of Polynomial 1 at x = 2: " << evaluation << std::endl;

    Polynomial derivative = utils.derivative(p1);
    std::cout << "Derivative of Polynomial 1: " << derivative << std::endl;

    return 0;
}