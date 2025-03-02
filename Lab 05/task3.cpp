#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    //constructor
    Book(string bookTitle, string bookAuthor, string bookIsbn)
        : title(bookTitle), author(bookAuthor), isbn(bookIsbn) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getIsbn() const {
        return isbn;
    }
};

class Catalog {
private:
    unordered_map<string, string> isbnToLocation; 

public:

    void addBook(const Book& book, string location) {
        isbnToLocation[book.getIsbn()] = location;
        cout << "Book added to catalog: " << book.getTitle() << " (ISBN: " << book.getIsbn() << ")" << endl;
    }

    string findBookLocation(string isbn) const {
        auto it = isbnToLocation.find(isbn);
        if (it != isbnToLocation.end()) {
            return it->second;
        }
        return "Book not found in catalog.";
    }
};

class Library {
private:
    string name;
    Catalog catalog;
    vector<Book*> books; 

public:
    //constructor
    Library(string libraryName) : name(libraryName) {
        cout << "Library '" << name << "' created with an internal catalog." << endl;
    }

    void addBook(Book* book, string location) {
        books.push_back(book);
        catalog.addBook(*book, location);
    }

    void removeBook(string isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->getIsbn() == isbn) {
                books.erase(it);
                cout << "Book removed from library: " << (*it)->getTitle() << " (ISBN: " << isbn << ")" << endl;
                return;
            }
        }
        cout << "Book not found in library: ISBN " << isbn << endl;
    }

    // Find a book's location in the catalog
    void findBookInCatalog(string isbn) const {
        string location = catalog.findBookLocation(isbn);
        cout << "Searching catalog for ISBN " << isbn << ": " << location << endl;
    }
};

int main() {

    Book* book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    Book* book2 = new Book("1984", "George Orwell", "9780451524935");
    Book* book3 = new Book("To Kill a Mockingbird", "Harper Lee", "9780061120084");

    Library library("Central Library");

    library.addBook(book1, "Fiction Section, Shelf 1");
    library.addBook(book2, "Fiction Section, Shelf 2");
    library.addBook(book3, "Fiction Section, Shelf 3");

    library.findBookInCatalog("9780743273565"); //The Great Gatsby. Born to be non-existent and DNE, forced to search Great Gatsby.
    library.findBookInCatalog("9780451524935"); //1984
    library.findBookInCatalog("9999999999999"); //Non-existent book. I get her(non-existent)

    library.removeBook("9780451524935"); //Remove 1984 (If it were this easy to remove ppl yk)

    library.findBookInCatalog("9780451524935");

    delete book1;
    delete book2;
    delete book3;

    return 0;
}
