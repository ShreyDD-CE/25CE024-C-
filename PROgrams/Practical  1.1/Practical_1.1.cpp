#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Wallet {
private:
    string walletID;
    string userName;
    double balance;

public:
    // Constructor
    Wallet(string id, string name, double initialBalance = 0.0)
        : walletID(id), userName(name), balance(initialBalance) {}

    // Load money into wallet
    void loadMoney(double amount) {
        if (amount <= 0) {
            cout << "Error: Amount must be positive.\n";
            return;
        }
        balance += amount;
        cout << "₹" << amount << " loaded successfully.\n";
    }

    // Transfer money to another wallet
    void transferMoney(Wallet &receiver, double amount) {
        if (amount <= 0) {
            cout << "Error: Amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            cout << "Error: Insufficient balance.\n";
            return;
        }
        balance -= amount;
        receiver.balance += amount;
        cout << "₹" << amount << " transferred to " << receiver.userName << ".\n";
    }

    // Display wallet details
    void displayDetails() const {
        cout << "Wallet ID: " << walletID << "\n"
             << "User Name: " << userName << "\n"
             << "Current Balance: ₹" << balance << "\n";
    }
};

// Example usage
int main() {
    Wallet w1("W001", "Alice", 500.0);
    Wallet w2("W002", "Bob", 200.0);

    w1.displayDetails();
    w2.displayDetails();

    w1.loadMoney(300);
    w1.transferMoney(w2, 600);  // valid transfer
    w1.transferMoney(w2, 500);  // insufficient balance

    w1.displayDetails();
    w2.displayDetails();

    return 0;
}
