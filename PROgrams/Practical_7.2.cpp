#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // 🔹 Overload + operator
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // 🔹 Overload - operator
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Display function
    void display() const {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }
};


int main() {

    Complex c1(4, 5);
    Complex c2(2, 3);

    // Addition
    Complex sum = c1 + c2;

    // Subtraction
    Complex diff = c1 - c2;

    cout << "First Complex: ";
    c1.display();

    cout << "Second Complex: ";
    c2.display();

    cout << "Addition Result: ";
    sum.display();

    cout << "Subtraction Result: ";
    diff.display();

    cout << "\n--- Batch Operations ---\n";

    Complex arr[3] = {
        Complex(1, 2),
        Complex(3, 4),
        Complex(5, 6)
    };

    Complex total;

    for (int i = 0; i < 3; i++) {
        total = total + arr[i];
    }

    cout << "Sum of all complex numbers: ";
    total.display();

    return 0;
}