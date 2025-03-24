#include<iostream>
using namespace std;

class Media {
    public:
    string title, publicationDate, publisher;
    int uniqueID;

    Media(string title, string publicationDate, string publisher, int uniqueID) {
        this->title = title;
        this->publicationDate = publicationDate;
        this->publisher = publisher;
        this->uniqueID = uniqueID;
    };

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "UniqueID: " << uniqueID << endl;        
    }

    void checkOut() {
        cout << "Media item checked out." << endl;
    }

    void returnItem() {
        cout << "Media item returned." << endl;
    }
};

class Book : public Media {
    public:
    string author;
    int numberOfPages;
    string ISBN;


    Book(string title, string pDate, string publ, int id, string a, int nump, string isbn) : Media(title, pDate, publ, id), author(a), ISBN(isbn), numberOfPages(nump) {};

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
        cout << "ISBN: " << ISBN << endl;
    }
};

class DVD : public Media {
    public:
    string director;
    int duration;
    double rating;

    DVD(string title, string pDate, string publ, int id, string dir, int time, double r) : Media(title, pDate, publ, id), director(dir), duration(time), rating(r) {}
    
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }

};


class CD : public Media {
    public:
    string artist;
    int numberOfTracks;
    string genre;

    CD(string title, string pDate, string publ, int id, string a, int numT, string g) : Media(title, pDate, publ, id),  artist(a), numberOfTracks(numT), genre(g) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};


int main() {
    Book book("To Kill a Laiba", "July 11, 1960", "J.B. Lippincott & Co.", 1, "Harper Lee", 281, "978-0061120084");
    DVD dvd("The Shawshank Redemption", "September 23, 1994", "Columbia Pictures", 2, "Frank Darabont", 142, 9.2);
    CD cd("Thriller", "November 30, 1982", "Epic Records", 3, "Michael Jackson", 9, "Pop");

    cout << "Book Information:" << endl;
    book.displayInfo();
    cout << endl;

    cout << "DVD Information:" << endl;
    dvd.displayInfo();
    cout << endl;

    cout << "CD Information:" << endl;
    cd.displayInfo();
    cout << endl;

    book.checkOut();
    dvd.returnItem();
    cd.checkOut();

    return 0;
}
