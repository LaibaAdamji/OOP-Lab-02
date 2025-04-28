#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

class Logger {
    string baseName = "log";
    int maxSize = 1024 * 1024;
    int currentFile = 1;
    
    string getFileName() {
        return baseName + to_string(currentFile) + ".txt";
    }
    
    void rotate() {
        if (filesystem::file_size(getFileName()) > maxSize) {
            currentFile++;
        }
    }
    
public:
    void log(const string& message) {
        rotate();
        ofstream file(getFileName(), ios::app);
        file << message << endl;
    }
};

int main() {
    Logger logger;
    for (int i = 0; i < 1000; i++) {
        logger.log("Log entry " + to_string(i));
    }
    return 0;
}
