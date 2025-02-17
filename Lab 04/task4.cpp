#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string author;
    string title;
    double price;
    string publisher;
    int stock;

public:
    //const
    Book(const string& auth, const string& ttl, double prc, const string& pub, int stk)
        : author(auth), title(ttl), price(prc > 0 ? prc : 0.0), publisher(pub), stock(stk > 0 ? stk : 0) {}

    bool isAvailable(const string& reqTitle, const string& reqAuthor) const {
        return title == reqTitle && author == reqAuthor;
    }
    void processRequest(int requestedCopies) const {
        if (requestedCopies <= stock) {
            cout << "Book is available. Total cost: " << (price * requestedCopies) <<endl;
        } else {
            cout << "Required copies not in stock." << endl;
        }
    }

    string getAuthor() const { return author; }
    string getTitle() const {return title; }
    double getPrice() const { return price;}
    string getPublisher() const { return publisher;}
    int getStock() const { return stock;}
};

class BookShop {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void searchBook(const string& title, const string& author) {
        for (const auto& book : books) {
            if (book.isAvailable(title, author)) {
                cout << "Book found: " <<book.getTitle() << " by " << book.getAuthor() << endl;
                int copies;
                cout << "Enter number of copies required: ";
                cin >> copies;
                book.processRequest(copies);
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

int main() {
    BookShop shop;
    shop.addBook(Book("J.K. Rowling", "Harry Potter",19.99, "Bloomsbury", 10));
    shop.addBook(Book("George Orwell", "1984", 9.99,"Penguins", 5));
    shop.searchBook("1984", "George Orwell");

    return 0;
}
