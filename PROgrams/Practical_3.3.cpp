#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    static int totalAccounts; // static member

    // Constructor
    BankAccount(int accNo, string name, double bal = 0) {
        accountNumber = accNo;
        holderName = name;

        if (bal < 0) {
            cout << "Invalid balance. Setting to 0.\n";
            balance = 0;
        } else {
            balance = bal;
        }

        totalAccounts++;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    // Deposit
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit!\n";
            return;
        }
        balance += amount;
    }

    // Withdraw
    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid or insufficient balance!\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    // Transfer
    void transfer(BankAccount &receiver, double amount) {
        if (withdraw(amount)) {
            receiver.deposit(amount);
            cout << "Transfer successful!\n";
        } else {
            cout << "Transfer failed!\n";
        }
    }

    // Display
    void display() const {
        cout << "\n--- Account Details ---\n";
        cout << "Account No: " << accountNumber << endl;
        cout << "Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Initialize static member
int BankAccount::totalAccounts = 0;

// 🔍 Find account by number
BankAccount* findAccount(BankAccount* accounts[], int n, int accNo) {
    for (int i = 0; i < n; i++) {
        if (accounts[i]->getAccountNumber() == accNo)
            return accounts[i];
    }
    return nullptr;
}

int main() {
    int n;

    cout << "Enter number of accounts: ";
    cin >> n;

    // Dynamic array of pointers
    BankAccount** accounts = new BankAccount*[n];

    int accNo;
    string name;
    double balance;

    // Create accounts
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for account " << i + 1 << ":\n";
        cout << "Account Number: ";
        cin >> accNo;
        cout << "Name: ";
        cin >> name;
        cout << "Initial Balance: ";
        cin >> balance;

        accounts[i] = new BankAccount(accNo, name, balance);
    }

    // Transfer simulation
    int from, to;
    double amount;

    cout << "\nEnter sender account number: ";
    cin >> from;
    cout << "Enter receiver account number: ";
    cin >> to;
    cout << "Enter amount: ";
    cin >> amount;

    BankAccount* sender = findAccount(accounts, n, from);
    BankAccount* receiver = findAccount(accounts, n, to);

    if (sender && receiver) {
        sender->transfer(*receiver, amount);
    } else {
        cout << "Invalid account number(s)!\n";
    }

    // Display all accounts
    for (int i = 0; i < n; i++) {
        accounts[i]->display();
    }

    cout << "\nTotal Accounts Created: " << BankAccount::totalAccounts << endl;

    // Free memory
    for (int i = 0; i < n; i++) {
        delete accounts[i];
    }
    delete[] accounts;

    return 0;
}