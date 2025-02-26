#include <iostream>
#include <stdexcept>
using namespace std;

class Polynomial {

private:
    int degree;
    double* coefficients;

    void allocateMemory(int deg) {
        coefficients = new double[deg + 1];
        for (int i = 0; i <= deg; ++i) {
            coefficients[i] = 0.0;
        }
    }

    void deallocateMemory() {
        if (coefficients) {
            delete[] coefficients;
        }
    }

public:
    //default constructor
    Polynomial() : degree(0) {
        allocateMemory(degree);
    }

    //parameterized constructor
    Polynomial(int deg, const double coeffs[]) : degree(deg) {
        allocateMemory(degree);
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeffs[i];
        }
    }

    //vopy constructor
    Polynomial(const Polynomial& other) : degree(other.degree) {
        allocateMemory(degree);
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    //move xonstructor
    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {
        other.degree = 0;
        other.coefficients = nullptr;
    }

    //destructor
    ~Polynomial() {
        deallocateMemory();
    }

    //get degree polynomial
    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0.0;
        double power = 1.0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * power;
            power *= x;
        }
        return result;
    }

    // Add two polynomials
    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        Polynomial result(maxDegree, new double[maxDegree + 1]);

        for (int i = 0; i <= maxDegree; ++i) {
            double coeff1 = (i <= degree) ? coefficients[i] : 0.0;
            double coeff2 = (i <= other.degree) ? other.coefficients[i] : 0.0;
            result.coefficients[i] = coeff1 + coeff2;
        }

        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        int resultDegree = degree + other.degree;
        Polynomial result(resultDegree, new double[resultDegree + 1]);

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                result.coefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return result;
    }

    void print() const {
        for (int i = 0; i <= degree; ++i) {
            cout << coefficients[i];
            if (i != 0) {
                cout << "x^" << i;
            }
            if (i != degree) {
                cout << " + ";
            }
        }
        cout << endl;
    }
};

int main() {
    double coeffs1[] = {1, 2, 3}; 
    Polynomial p1(2, coeffs1);
    cout << "Polynomial p1: ";
    p1.print();

    double coeffs2[] = {4, 5}; 
    Polynomial p2(1, coeffs2);
    cout << "Polynomial p2: ";
    p2.print();

    Polynomial p3 = p1.add(p2);
    cout << "p1 + p2: ";
    p3.print();

    Polynomial p4 = p1.multiply(p2);
    cout << "p1 * p2: ";
    p4.print();

    cout << "p1 evaluated at x = 2: " << p1.evaluate(2) << endl;

    return 0;
}
