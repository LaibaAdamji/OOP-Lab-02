#include <iostream>
using namespace std;

class Glass{
    public:
        int LiquidLevel = 200;

        void Drink(int millimeters){
            LiquidLevel = 200 - millimeters;

            if (LiquidLevel < 100){
                Refill();
            }
        }

        void Refill(){
            LiquidLevel = 200;
            cout << "Glass refilled to 200\n";
        }
};

int main(){
    Glass obj;
    int level;

    while (level >= 0 && level <= 200){
        cin >> level;
        obj.Drink(level);
    }

    return 0;

}