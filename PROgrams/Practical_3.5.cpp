#include <iostream>
using namespace std;

// 🔁 Recursive function to find super digit
int superDigit(long long num) {
    if (num < 10)
        return num;

    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return superDigit(sum);
}

// 🔹 Optimized function
int findSuperDigit(string n, int k) {
    long long initialSum = 0;

    // Sum digits of string n
    for (char c : n) {
        initialSum += (c - '0');
    }

    // Multiply by k instead of concatenation
    initialSum *= k;

    return superDigit(initialSum);
}

int main() {
    string n;
    int k;

    cout << "Enter number (as string): ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    cout << "Super Digit: " << findSuperDigit(n, k) << endl;

    return 0;
}