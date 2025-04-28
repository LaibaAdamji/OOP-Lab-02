
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encrypt(const string& text) {
    string encrypted_text;
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        int ascii_val = (int)c;
        int encrypted_val = ascii_val + (i + 1);
        encrypted_text += (char)encrypted_val;
    }
    return encrypted_text;
}

string decrypt(const string& encrypted_text) {
    string decrypted_text;
    for (int i = 0; i < encrypted_text.length(); i++) {
        char c = encrypted_text[i];
        int ascii_val = (int)c;
        int decrypted_val = ascii_val - (i + 1);
        decrypted_text += (char)decrypted_val;
    }
    return decrypted_text;
}

// Function to write text to a file
void write_to_file(const string& text, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << text;
        file.close();
    } else {
        cout << "Unable to open file";
    }
}

string read_from_file(const string& filename) {
    ifstream file(filename);
    string text;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            text += line;
        }
        file.close();
    } else {
        cout << "Unable to open file";
    }
    return text;
}

int main() {
    string text;
    cout << "Enter String: ";
    getline(cin, text);
    cout << "Normal Text: " << text << endl;

    string encrypted_text = encrypt(text);
    cout << "Encrypted text inserted in file" << endl;
    cout << encrypted_text << endl;

    string filename = "encrypted_text.txt";
    write_to_file(encrypted_text, filename);

    string read_text = read_from_file(filename);
    string decrypted_text = decrypt(read_text);
    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decrypted_text << endl;

    return 0;
}
