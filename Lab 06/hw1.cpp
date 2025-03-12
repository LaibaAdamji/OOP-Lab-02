#include <iostream>
#include <string>
using namespace std;


class Books {
protected:
    string genre;

public:
    Books(const string& g) : genre(g) {}

    virtual void displayDetails() const {
        cout << "Genre:" <<genre << endl;
    }
};


class Novel : public Books{
private:
    string title;
    string author;

public:
    Novel(const string& t, const string& a)
        : Books("Novel"),title(t), author(a){}

    void displayDetails() const override {
        Books::displayDetails();
        cout << "Title: "<< title <<", Author: " << author << endl;
    }
};


class Mystery : public Books {
private:
    string title;
    string author;

public:
    Mystery(const string& t, const string& a)
        : Books("Mystery"), title(t), author(a) {}

    void displayDetails() const override {
        Books::displayDetails();
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

int main() {

    Novel novel("The great urge to sleep and not do oop assignments and flunk on my midterm", "ehehe");
    Mystery mystery("The Girl on the train ig?", "xyz author");


    novel.displayDetails();
    cout << endl;
    mystery.displayDetails();

    return 0;
}
