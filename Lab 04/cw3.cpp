#include <iostream>
#include <stdexcept>

using namespace std;

class DynamicArray {
private:
    int* data;
    size_t size;

    void allocateMemory(size_t newSize) {
        data = new int[newSize];
        for (size_t i = 0; i < newSize; ++i) {
            data[i] = 0;
        }
    }

    void deallocateMemory() {
        if (data) {
            delete[] data;
            data = nullptr;
        }
    }

public:
    //constructor
    DynamicArray() : data(nullptr), size(0) {}

    //parameterized constructor
    DynamicArray(size_t n) : size(n) {
        allocateMemory(size);
    }

    //copy constructor
    DynamicArray(const DynamicArray& other) : size(other.size) {
        allocateMemory(size);
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    //move constructor
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    //destructor
    ~DynamicArray() {
        deallocateMemory();
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            deallocateMemory();
            size = other.size;
            allocateMemory(size);
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }


    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            deallocateMemory();
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    size_t getSize() const {
        return size;
    }

    int& at(size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    const int& at(size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr1(5);
    cout << "Array 1: ";
    arr1.print();

    arr1.at(2) = 10;
    cout << "Array 1 after modification: ";
    arr1.print();

    DynamicArray arr2 = arr1; //copy const
    cout << "Array 2 (copy of Array 1): ";
    arr2.print();

    DynamicArray arr3 = move(arr1); //move const
    cout << "Array 3 (moved from Array 1): ";
    arr3.print();
    cout << "Array 1 after move: ";
    arr1.print(); //should be empty

    DynamicArray arr4;
    arr4 = arr3; //copy assignment
    cout << "Array 4 (copy assigned from Array 3): ";
    arr4.print();

    DynamicArray arr5;
    arr5 = move(arr3); //move assignment
    cout << "Array 5 (move assigned from Array 3): ";
    arr5.print();
    cout << "Array 3 after move assignment: ";
    arr3.print(); //sould be empty

    return 0;
}
