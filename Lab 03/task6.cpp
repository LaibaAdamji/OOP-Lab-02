#include <iostream>
#include <vector>
#include <cstdlib> //stoi um??

class Matrix {
private:
    int rows, cols;
    std::vector<std::vector<int>> data;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<int>(c, 0)) {}

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            data[i][j] = value;
        } else {
            std::cerr << "Invalid index (" << i << ", " << j << ") for setting element.\n";
        }
    }

    void display() const {
        for (const auto& row : data) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }

    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrices cannot be added\n";
            return Matrix(0, 0); //empty matrix return
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }

    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            std::cerr << "Matrices cannot be multiplied\n";
            return Matrix(0, 0);
        }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < other.cols; j++)
            for (int k = 0; k < cols; k++)
                result.data[i][j] += data[i][k] * other.data[k][j];

        return result;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " rows1 cols1 elements1 rows2 cols2 elements2\n";
        return 1;
    }

    int rows1 = std::stoi(argv[1]);
    int cols1 = std::stoi(argv[2]);
    int startIdx1 = 3;
    
    if (argc < startIdx1 + rows1 * cols1 + 2) {
        std::cerr << "Not enough elements provided for the first matrix.\n";
        return 1;
    }

    //1st matrix
    Matrix mat1(rows1, cols1);
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols1; j++)
            mat1.setElement(i, j, std::stoi(argv[startIdx1 + i * cols1 + j]));

    int startIdx2 = startIdx1 + rows1 * cols1;
    int rows2 = std::stoi(argv[startIdx2]);
    int cols2 = std::stoi(argv[startIdx2 + 1]);

    if (argc < startIdx2 + 2 + rows2 * cols2) {
        std::cerr << "Not enuff elements provided.\n";
        return 1;
    }

    //2nd matrixx
    Matrix mat2(rows2, cols2);
    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols2; j++)
            mat2.setElement(i, j, std::stoi(argv[startIdx2 + 2 + i * cols2 + j]));

    //output
    std::cout << "Matrix 1:\n";
    mat1.display();
    
    std::cout << "\nMatrix 2:\n";
    mat2.display();

    //add
    std::cout << "\nMatrix Addition:\n";
    Matrix sum = mat1.add(mat2);
    sum.display();

    //multiply
    std::cout << "\nMatrix Multiplication:\n";
    Matrix product = mat1.multiply(mat2);
    product.display();

    return 0;
}
