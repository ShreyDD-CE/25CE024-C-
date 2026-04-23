#include <iostream>
using namespace std;

class Calculator {
private:
    double results[100]; // store results
    int count;

public:
    Calculator() {
        count = 0;
    }

    // 🔹 Overloaded functions
    int add(int a, int b) {
        int res = a + b;
        results[count++] = res;
        return res;
    }

    double add(double a, double b) {
        double res = a + b;
        results[count++] = res;
        return res;
    }

    double add(int a, double b) {
        double res = a + b;
        results[count++] = res;
        return res;
    }

    double add(double a, int b) {
        double res = a + b;
        results[count++] = res;
        return res;
    }

    // 🔹 Display all results
    void displayResults() const {
        cout << "\n--- Calculation Results ---\n";
        for (int i = 0; i < count; i++) {
            cout << "Result " << i + 1 << ": " << results[i] << endl;
        }
    }
};

// ===============================
// 🔹 MAIN
// ===============================
int main() {
    Calculator calc;

    // Test cases
    cout << "Int + Int: " << calc.add(10, 20) << endl;
    cout << "Double + Double: " << calc.add(5.5, 2.3) << endl;
    cout << "Int + Double: " << calc.add(7, 3.8) << endl;
    cout << "Double + Int: " << calc.add(4.2, 6) << endl;

    // Display stored results
    calc.displayResults();

    return 0;
}