#include <iostream>
#include <cstring>
#include <cstdio>  // For sprintf if needed, but basics here

using namespace std;

class Book {
private:
    int id;
    char title[100];
    char author[100];
    int copies;
public:
    // Constructor
    Book() { id = 0; title[0] = '\0'; author[0] = '\0'; copies = 0; }
    
    // Setters
    void setId(int i) { id = i; }
    void setTitle(const char* t) { strcpy(title, t); }
    void setAuthor(const char* a) { strcpy(author, a); }
    void setCopies(int c) { copies = c; }
    
    // Getters
    int getId() { return id; }
    int getCopies() { return copies; }
    void showDetails() {
        cout << "ID: " << id << ", Title: " << title 
             << ", Author: " << author << ", Copies: " << copies << endl;
    }
    
    // Operations
    bool issueBook() {
        if (copies > 0) {
            copies--;
            return true;
        }
        return false;
    }
    void returnBook() { copies++; }
};

class Library {
private:
    Book books[100];  // Fixed array for simplicity
    int totalBooks;
public:
    Library() { totalBooks = 0; }
    
    void addBook() {
        if (totalBooks >= 100) {
            cout << "Library full!" << endl;
            return;
        }
        Book& b = books[totalBooks];
        cout << "Enter ID, Title, Author, Copies: ";
        int id, copies;
        char title[100], author[100];
        cin >> id >> title >> author >> copies;
        b.setId(id);
        b.setTitle(title);
        b.setAuthor(author);
        b.setCopies(copies);
        totalBooks++;
        cout << "Book added." << endl;
    }
    
    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;
        for (int i = 0; i < totalBooks; i++) {
            if (books[i].getId() == id) {
                if (books[i].issueBook()) {
                    cout << "Issued successfully." << endl;
                } else {
                    cout << "No copies available!" << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }
    
    void returnBookFunc() {  // Named to avoid keyword conflict
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;
        for (int i = 0; i < totalBooks; i++) {
            if (books[i].getId() == id) {
                books[i].returnBook();
                cout << "Returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }
    
    void displayTotal() {
        cout << "Total books in library: " << totalBooks << endl;
    }
    
    void displayAll() {
        cout << "All books:" << endl;
        for (int i = 0; i < totalBooks; i++) {
            books[i].showDetails();
        }
    }
};

int main() {
    Library lib;
    int choice;
    while (true) {
        cout << "\n1. Add Book\n2. Issue Book\n3. Return Book\n4. Total Books\n5. Display All\n6. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.issueBook(); break;
            case 3: lib.returnBookFunc(); break;
            case 4: lib.displayTotal(); break;
            case 5: lib.displayAll(); break;
            case 6: return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}