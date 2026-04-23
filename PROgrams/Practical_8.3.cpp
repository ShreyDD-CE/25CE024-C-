#include <iostream>
using namespace std;

// ===============================
// 🔹 BankAccount Class
// ===============================
class BankAccount {
private:
    double balance;

public:
    BankAccount(double b = 0) : balance(b) {}

    void deposit(double amount, string log[], int &idx) {
        log[idx++] = "Entered deposit()";

        if (amount <= 0) {
            throw "Invalid deposit amount!";
        }

        balance += amount;
        log[idx++] = "Deposit successful";

        log[idx++] = "Exiting deposit()";
    }

    void withdraw(double amount, string log[], int &idx) {
        log[idx++] = "Entered withdraw()";

        if (amount > balance) {
            throw "Error: Insufficient balance!";
        }

        balance -= amount;
        log[idx++] = "Withdrawal successful";

        log[idx++] = "Exiting withdraw()";
    }

    double getBalance() const {
        return balance;
    }
};

// ===============================
// 🔹 Layer 1 Function
// ===============================
void transactionLayer(BankAccount &acc, string log[], int &idx) {
    log[idx++] = "Entered transactionLayer()";

    acc.deposit(500, log, idx);
    acc.withdraw(2000, log, idx);  // ❌ will throw

    log[idx++] = "Exiting transactionLayer()"; // ❌ never reached
}

// ===============================
// 🔹 Layer 2 Function
// ===============================
void serviceLayer(BankAccount &acc, string log[], int &idx) {
    log[idx++] = "Entered serviceLayer()";

    transactionLayer(acc, log, idx);

    log[idx++] = "Exiting serviceLayer()"; // ❌ never reached
}

// ===============================
// 🔹 MAIN
// ===============================
int main() {
    string log[100];
    int idx = 0;

    BankAccount acc(1000);

    try {
        log[idx++] = "Entered main() try block";

        serviceLayer(acc, log, idx);

        log[idx++] = "Exiting main() try block"; // ❌ skipped
    }
    catch (const char* msg) {
        log[idx++] = "Exception caught in main()";
        cout << "Exception: " << msg << endl;
    }

    // ===============================
    // 🔹 Display Logs
    // ===============================
    cout << "\n--- Execution Log ---\n";
    for (int i = 0; i < idx; i++) {
        cout << log[i] << endl;
    }

    cout << "\nFinal Balance: " << acc.getBalance() << endl;

    return 0;
}    