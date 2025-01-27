
#include<iostream>
using namespace std;
int main(){
    int nums[5], i;
    for (i = 0; i < 5; i++) {
        cout << "Enter number: " << i + 1 << ": ";
        cin >> nums[i];
    }
    int *max = 0, *secLarge = 0;
    for (i = 0; i < 5; i++) {
        if (!max || nums[i] > *max) {
            secLarge = max;
            max = &nums[i];
        } else if ((!secLarge || nums[i] > *secLarge) && nums[i] != *max) {
            secLarge = &nums[i];
        }
    }
    if (secLarge) {
        cout << "the second largest number in the array is: " << *secLarge << endl;
    } else {
        cout << "No second largest number found lol loser";
    }
    return 0;
}
