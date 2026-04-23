#include <iostream>
#include <vector>
using namespace std;

class DigitalAccount {
private:
    string customerName;
    int accountID;
    double balance;

public:
    // Constructor
    DigitalAccount(string name, int id, double initialBalance = 0.0) {
        customerName = name;
        accountID = id;

        if (initialBalance < 0) {
            cout << "Invalid initial balance. Setting to 0.\n";
            balance = 0;
        } else {
            balance = initialBalance;
        }
    }

    // Deposit function
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!\n";
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!\n";
            return;
        }

        if (amount > balance) {
            cout << "Withdrawal failed! Insufficient balance.\n";
            return;
        }

        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    }

    // Display summary
    void displaySummary() const {
        cout << "\n--- Account Summary ---\n";
        cout << "Name: " << customerName << endl;
        cout << "Account ID: " << accountID << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    vector<DigitalAccount> accounts;

    // Simulating multiple accounts
    accounts.push_back(DigitalAccount("Shrey", 101, 500));
    accounts.push_back(DigitalAccount("Amit", 102));
    accounts.push_back(DigitalAccount("Neha", 103, -200)); // edge case

    // Transactions
    accounts[0].deposit(200);
    accounts[0].withdraw(100);

    accounts[1].withdraw(50);   // edge case: no balance
    accounts[1].deposit(300);

    accounts[2].deposit(150);
    accounts[2].withdraw(500);  // edge case: overdraft

    // Display summaries
    for (const auto &acc : accounts) {
        acc.displaySummary();
    }

    return 0;
}