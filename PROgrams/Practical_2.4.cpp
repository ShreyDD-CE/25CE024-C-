#include <iostream>
#include <vector>
using namespace std;

class Item {
private:
    int itemID;
    string itemName;
    double price;
    int quantity;

public:
    // Default constructor
    Item() {
        itemID = 0;
        itemName = "Unknown";
        price = 0.0;
        quantity = 0;
    }

    // Parameterized constructor
    Item(int id, string name, double p, int q) {
        itemID = id;
        itemName = name;

        if (p < 0) {
            cout << "Invalid price. Setting to 0.\n";
            price = 0;
        } else {
            price = p;
        }

        if (q < 0) {
            cout << "Invalid quantity. Setting to 0.\n";
            quantity = 0;
        } else {
            quantity = q;
        }
    }

    // Increase stock
    void addStock(int amount) {
        if (amount <= 0) {
            cout << "Invalid stock addition!\n";
            return;
        }
        quantity += amount;
        cout << amount << " items added to stock.\n";
    }

    // Sell item
    void sellItem(int amount) {
        if (amount <= 0) {
            cout << "Invalid sale quantity!\n";
            return;
        }

        if (amount > quantity) {
            cout << "Sale failed! Not enough stock.\n";
            return;
        }

        quantity -= amount;
        cout << amount << " items sold.\n";
    }

    // Display details
    void displayItem() const {
        cout << "\n--- Item Details ---\n";
        cout << "ID: " << itemID << endl;
        cout << "Name: " << itemName << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << quantity << endl;
    }
};

int main() {
    vector<Item> inventory;

    // Creating multiple items
    inventory.push_back(Item(1, "Laptop", 50000, 10));
    inventory.push_back(Item(2, "Mouse", 500, 50));
    inventory.push_back(Item(3, "Keyboard", -1000, -5)); // edge case

    // Simulating operations
    inventory[0].sellItem(2);
    inventory[0].addStock(5);

    inventory[1].sellItem(60); // edge case: more than stock
    inventory[1].addStock(20);

    inventory[2].addStock(10);
    inventory[2].sellItem(3);

    // Display all items
    for (const auto &item : inventory) {
        item.displayItem();
    }

    return 0;
}