#include <iostream>
using namespace std;

class Account {
protected:
    int accNo;
    double balance;

    // Simple transaction history (stack-like)
    double history[100];
    int top;

public:
    Account(int acc, double bal) : accNo(acc), balance(bal), top(-1) {
        cout << "Account Created\n";
    }

    virtual ~Account() {
        cout << "Account Destroyed\n";
    }

    // Deposit
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }
        balance += amount;
        history[++top] = amount; // store positive
    }

    // Withdraw (basic)
    virtual void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid withdrawal!\n";
            return;
        }
        balance -= amount;
        history[++top] = -amount; // store negative
    }

    // Undo last transaction
    void undo() {
        if (top < 0) {
            cout << "No transaction to undo!\n";
            return;
        }

        double last = history[top--];
        balance -= last; // reverse operation
        cout << "Last transaction undone.\n";
    }

    virtual void display() const {
        cout << "\nAccount No: " << accNo
             << "\nBalance: " << balance << endl;
    }
};

// ===============================
// 🔹 Savings Account
// ===============================
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int acc, double bal, double rate)
        : Account(acc, bal), interestRate(rate) {}

    void display() const override {
        cout << "\n--- Savings Account ---\n";
        Account::display();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

// ===============================
// 🔹 Current Account
// ===============================
class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(int acc, double bal, double limit)
        : Account(acc, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= 0 || amount > balance + overdraftLimit) {
            cout << "Withdrawal exceeds overdraft limit!\n";
            return;
        }
        balance -= amount;
        history[++top] = -amount;
    }

    void display() const override {
        cout << "\n--- Current Account ---\n";
        Account::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

// ===============================
// 🔹 MAIN
// ===============================
int main() {

    // Create accounts
    SavingsAccount s(101, 5000, 5.0);
    CurrentAccount c(102, 3000, 2000);

    // Operations
    s.deposit(1000);
    s.withdraw(200);
    s.undo();

    c.deposit(500);
    c.withdraw(4000); // uses overdraft
    c.undo();

    // Display
    s.display();
    c.display();

    return 0;
}