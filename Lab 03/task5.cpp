#include <iostream>
#include <string>

class Book {
private:
    std::string bookName;
    std::string isbn;
    std::string author;
    std::string publisher;

public:
    Book(std::string bName, std::string bIsbn, std::string bAuthor, std::string bPublisher)
        : bookName(bName), isbn(bIsbn), author(bAuthor), publisher(bPublisher) {}

    std::string getBookInfo() const {
        return "Book: " + bookName + "\nISBN: " + isbn + "\nAuthor: " + author + "\nPublisher: " + publisher;
    }
};

int main(int argc, char *argv[]) {
    if (argc != 21) { //5  * 4 args + 1 
        std::cerr << "Usage: " << argv[0] << " Book1Name ISBN1 Author1 Publisher1.. so on\n";
        return 1;
    }
    Book book[5] = {
        Book(argv[1], argv[2], argv[3], argv[4]),
        Book(argv[5], argv[6], argv[7], argv[8]),
        Book(argv[9], argv[10], argv[11], argv[12]),
        Book(argv[13], argv[14], argv[15], argv[16]),
        Book(argv[17], argv[18], argv[19], argv[20])
    };

    for (int i = 0; i < 5; i++) {
        std::cout << "\nBook " << (i + 1) << " Details:\n";
        std::cout << book[i].getBookInfo() << "\n";
    }

    return 0;
}
