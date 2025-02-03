#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "less than 2 numbers. can't sum?? lol\n";
        return 1;
    }
    int sum = 0;
    int* ptr; //ptr for iteration
    for (int i = 1; i < argc; i++) {
        int num = std::atoi(argv[i]); // type casting
        ptr = &num; 
        sum += *ptr; 
    }
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}

