#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
    int degree;
    double* coefficients;

    public:
        Polynomial() : degree(0) {
            coefficients = new double[1]{0};
        }

        Polynomial(int deg, const double coeff[]) : degree(deg) {
            coefficients = new double[degree + 1];

            for (int i = 0; i <= degree; i++){
                coefficients[i] = coeff[i];
            }
        }

        Polynomial(const Polynomial& other) : degree(other.degree) {
            coefficients = new double[degree + 1];
            for (int i = 0 ; i <= degree; i++){
                coefficients[i] = other.coefficients[i];
            }
        }

        Polynomial(Polynomial&& other) noexcept : degree(other.degree) , coefficients(other.coefficients) {
            other.coefficients = nullptr;
            other.degree = 0;
        }

        ~Polynomial() {
            delete[] coefficients;
        }

        int getDegree() const{
            return degree;
        }

        double evaluate(double x) const {
            double result = 0;
            for (int i = 0; i <= degree; i++){
                result+=coefficients[i]+pow(x, i);
            }
            return result;
        }

        Polynomial add(const Polynomial& other) const {
            int maxdeg = max(degree, other.degree);
            double* newcoeff = new double[maxdeg+1]{0};

            for (int i = 0; i <= degree; i++){
                newcoeff[i] += coefficients[i];
            }

            for (int i = 0; i <= other.degree; i++) {
                newcoeff[i] += other.coeff[i];
            }
        }
};