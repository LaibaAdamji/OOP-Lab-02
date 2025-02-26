#include <iostream>
using namespace std;

class Matrix {
private:

    int rows, cols;
    double** data;

    void allocateMemory() {
      
        data = new double*[rows];
      
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
        }
    }

    void deallocateMemory() {
        if (data) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
    }

public:
    //default constructor
    Matrix() : rows(0), cols(0), data(nullptr) {}

    //parameterized constructor
    Matrix(int r, int c) : rows(r), cols(c), data(nullptr) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0.0;
            }
        }
    }

    //copy constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(nullptr) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    //move constructor
    Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(other.data) {
        other.rows = 0;
        other.cols = 0;
        other.data = nullptr;
    }

    //destructor
    ~Matrix() {
        deallocateMemory();
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    double& at(int r, int c) {
        return data[r][c];
    }

    void fill(double value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = value;
            }
        }
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.at(j, i) = data[i][j];
            }
        }
        return result;
    }
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1(3, 3);
    m1.fill(1.0);
    m1.at(1, 1) = 2.0;
    cout << "Original Matrix:" << endl;
    m1.print();

    Matrix m2 = m1.transpose();
    cout << "Transposed Matrix:" << endl;
    m2.print();

    return 0;
}
