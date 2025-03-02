#include <iostream>
#include <thread> //For std::this_thread::sleep_for | btw this would've been way easier and efficient if we did this in python??? why does HEC hate us????
#include <chrono> //For std::chrono::seconds
using namespace std;

class Blend {
public:
    void blend() {
        cout << "Blending selected fruits..." << endl;
        for (int i = 1; i <= 5; ++i) {
            cout << "Blending in progress... " << i << " seconds" << endl;
            this_thread::sleep_for(chrono::seconds(1)); //sleep for 1sec
        }
        cout << "Blending complete!" << endl;
    }
};

class Grind {
public:
    void grind() {
        cout << "Grinding selected fruits..." << endl;
        this_thread::sleep_for(chrono::seconds(5)); //sleep for 5secs
        cout <<"Grinding complete!" << endl;
    }
};

class JuiceMaker {
private:
    Blend blender; 
    Grind grinder; 

public:
    void blendJuice() {
        cout << "Starting blend process..." << endl;
        blender.blend();
    }

    void grindJuice() {
        cout << "Starting grind process..." << endl;
        grinder.grind();
    }
};

int main() {
    JuiceMaker juiceMaker;

    cout << "--- Blending Juice. Do you not have a roza? ---" << endl;
    juiceMaker.blendJuice();

    cout << "\n--- Grinding Juice. What's the difference? ---" << endl;
    juiceMaker.grindJuice();

    return 0;
}
