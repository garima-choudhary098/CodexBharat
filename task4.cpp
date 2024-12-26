#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Book class to represent a book in the library
class Book {
private:
    string title;
    string author;
    string isbn;

public:
    // Default Constructor
    Book() {}

    // Parameterized Constructor
    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }

    // Display Book Info
    void displayBook() const {
        cout << left << setw(30) << "Title: " << title << endl
             << left << setw(30) << "Author: " << author << endl
             << left << setw(30) << "ISBN: " << isbn << endl;
    }

    // Write Book data to a file
    void saveToFile(ofstream &outFile) const {
        outFile << title << '\n' << author << '\n' << isbn << '\n';
    }

    // Read Book data from a file
    void loadFromFile(ifstream &inFile) {
        getline(inFile, title);
        getline(inFile, author);
        getline(inFile, isbn);
    }
};

// Library class to manage multiple books
class Library {
private:
    vector<Book> books;
    const string filename = "books.txt";

    // Load books from file
    void loadBooksFromFile() {
        ifstream inFile(filename);
        if (!inFile) return;

        Book book;
        while (true) {
            book.loadFromFile(inFile);
            if (inFile.eof()) break;
            books.push_back(book);
        }
        inFile.close();
    }

    // Save books to file
    void saveBooksToFile() {
        ofstream outFile(filename);
        for (const auto &book : books) {
            book.saveToFile(outFile);
        }
        outFile.close();
    }

public:
    // Constructor
    Library() { loadBooksFromFile(); }

    // Destructor
    ~Library() { saveBooksToFile(); }

    // Add a new book
    void addBook() {
        string title, author, isbn;
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);
        cout << "Enter Book ISBN: ";
        getline(cin, isbn);

        books.emplace_back(title, author, isbn);
        cout << "Book added successfully!" << endl;
    }

    // Delete a book by ISBN
    void deleteBook() {
        string isbn;
        cout << "Enter ISBN of the book to delete: ";
        cin.ignore();
        getline(cin, isbn);

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getISBN() == isbn) {
                books.erase(it);
                cout << "Book deleted successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Search for a book by Title or Author
    void searchBook() const {
        int choice;
        cout << "Search by: 1. Title  2. Author\nEnter choice: ";
        cin >> choice;

        string keyword;
        cin.ignore();
        if (choice == 1) {
            cout << "Enter Book Title: ";
            getline(cin, keyword);
            for (const auto &book : books) {
                if (book.getTitle() == keyword) {
                    book.displayBook();
                    return;
                }
            }
        } else if (choice == 2) {
            cout << "Enter Book Author: ";
            getline(cin, keyword);
            for (const auto &book : books) {
                if (book.getAuthor() == keyword) {
                    book.displayBook();
                    return;
                }
            }
        }
        cout << "Book not found!" << endl;
    }

    // Display all books
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }

        cout << "\n--- Library Books ---\n";
        for (const auto &book : books) {
            book.displayBook();
            cout << "-----------------------------\n";
        }
    }
};

// Menu to interact with the library system
void displayMenu() {
    cout << "\n===== Library Management System =====" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Delete Book" << endl;
    cout << "3. Search Book" << endl;
    cout << "4. Display All Books" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.deleteBook();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.displayAllBooks();
                break;
            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
