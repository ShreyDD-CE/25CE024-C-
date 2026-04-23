#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string filename = "inventory.txt";

// 🔹 Add item
void addItem() {
    ofstream file(filename, ios::app);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    string name;
    int quantity;
    double price;

    cout << "Enter item name: ";
    cin >> name;

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter price: ";
    cin >> price;

    file << name << " " << quantity << " " << price << endl;

    file.close();

    cout << "Item added successfully!\n";
}

// 🔹 View all items
void viewItems() {
    ifstream file(filename);

    if (!file) {
        cout << "No inventory file found!\n";
        return;
    }

    string name;
    int quantity;
    double price;

    cout << "\n--- Inventory List ---\n";

    while (file >> name >> quantity >> price) {
        cout << "Name: " << name
             << " | Quantity: " << quantity
             << " | Price: " << price << endl;
    }

    file.close();
}

// 🔹 Search item
void searchItem() {
    ifstream file(filename);

    if (!file) {
        cout << "File not found!\n";
        return;
    }

    string searchName;
    cout << "Enter item name to search: ";
    cin >> searchName;

    string name;
    int quantity;
    double price;

    bool found = false;

    while (file >> name >> quantity >> price) {
        if (name == searchName) {
            cout << "\nItem Found!\n";
            cout << "Name: " << name
                 << " | Quantity: " << quantity
                 << " | Price: " << price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item not found.\n";
    }

    file.close();
}

// 🔹 Main menu
int main() {
    int choice;

    do {
        cout << "\n--- Inventory Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. View All Items\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewItems(); break;
            case 3: searchItem(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}