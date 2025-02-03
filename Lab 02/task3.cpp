#include <iostream>

void reArr(int*& arr, int& cap) {
    int newCap = cap * 2;
    int* newArr = new int[newCap];

    for (int i = 0; i < cap; i++){
        newArr[i] = arr[i];} 
    delete[] arr; 
    arr = newArr; 
    cap = newCap; 
}

int main() {
    int cap = 5, size = 0;
    int* arr = new int[cap];

    for (int i = 0; i < 12; i++) { 
        if (size >= cap){ 
            reArr(arr, cap);}        
        arr[size++] = i * 2; 
    }

    std::cout << "resized array: ";
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";}
    delete[] arr;
    return 0;
}
