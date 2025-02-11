#include <iostream>
using namespace std;



class Matrix {
    double rows, cols;
    double *arr;

    public:
        Matrix() : rows(0), cols(0), arr(nullptr){} //default

        Matrix(int r, int c) : rows(r), cols(c) {

            if (r <= 0 || c <= 0){
                rows = cols = 0;
                arr = nullptr;
            } else {
                arr = new double[rows*cols](); //elements = 0
            }
        }

        //copy const

        Matrix(const Matrix& other) : rows(other.rows) , cols(other.cols) {
            if (other.arr){
                arr = new double[rows*cols];
                for (int i = 0; i < rows * cols; ++i){
                    arr[i] = other.arr[i];
                }
            }
        }

        //move const

        Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), arr(other.arr) {
            other.rows = other.cols = 0;
            other.arr = nullptr;
        }

        ~Matrix(){
            delete[] arr;
        }


        //getter

        int getRows() const{
            return rows;
        }

        int getCols() const{
            return cols;
        }

        double& at(int r, int c){
            if (r <0 || r >= rows || c<0 || c >= cols){
                throw std::out_of_range("loser index out of range wow sucks2buu");
            }
            return arr[r*cols + c];
        }

        void fill(double val){
            for (int i = 0; i < rows*cols; ++i){
                
            }
        }

};

































