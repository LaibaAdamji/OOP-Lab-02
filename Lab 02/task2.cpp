#include <iostream>

void modArray(void* arr, int size) {
    int* intArr = static_cast<int*>(arr); //void* to int*  
    for (int i = 0; i < size; i++) {
        intArr[i] += 7; //adding 7 for funsies. also fav number? why does everyone like 7. exactly like the other girls.
    }
}

int main() {
    int arr[] = {1, 2, 23, 7, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "original array: ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    
    modArray(arr, size);
    std::cout << "\nmodded array: ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    
    return 0;
}
