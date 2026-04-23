#include <iostream>
using namespace std;

int main() {
    int a, b;

    try {
        cout << "Enter two integers (numerator denominator): ";

        // Try reading input
        if (!(cin >> a >> b)) {
            throw "Invalid input! Please enter integers only.";
        }

        // Check division by zero immediately
        if (b == 0) {
            throw "Error: Division by zero!";
        }

        // Perform division immediately
        cout << "Result: " << (a / b) << endl;
    }

    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}