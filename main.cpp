#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool issued;

public:
    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        issued = false;
    }

    int getID() {
        return id;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Status: " << (issued ? "Issued" : "Available") << endl;
        cout << "---------------------\n";
    }

    void issue() {
        if (!issued) {
            issued = true;
            cout << "Book issued successfully.\n";
        } else {
            cout << "Book already issued.\n";
        }
    }

    void returnBook() {
        issued = false;
        cout << "Book returned.\n";
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;

        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully.\n";
    }

    void displayBooks() {
        for (auto &b : books) {
            b.display();
        }
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;

        for (auto &b : books) {
            if (b.getID() == id) {
                b.issue();
                return;
            }
        }

        cout << "Book not found.\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        for (auto &b : books) {
            if (b.getID() == id) {
                b.returnBook();
                return;
            }
        }

        cout << "Book not found.\n";
    }
void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (auto &b : books) {
        if (b.getID() == id) {
            cout << "Book Found:\n";
            b.display();
            return;
        }
    }

    cout << "Book not found.\n";
}
};

int main() {
    Library lib;
    int choice;

    while (true) {
      cout << "\n--- Library Management System ---\n";
cout << "1. Add Book\n";
cout << "2. Display Books\n";
cout << "3. Issue Book\n";
cout << "4. Return Book\n";
cout << "5. Search Book\n";
cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.displayBooks();
            break;
        case 3:
            lib.issueBook();
            break;
        case 4:
            lib.returnBook();
            break;
        case 5:
            lib.searchBook();
            break;
        case 6:
            cout<<"Exiting...\n";
       return 0;
             default:
            cout << "Invalid choice\n";
        }
    }
}
