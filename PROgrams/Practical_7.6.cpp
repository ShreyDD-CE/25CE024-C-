#include <iostream>
using namespace std;

class Base {
public:
    ~Base() {
        cout << "Base Destructor Called\n";
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[5]; // dynamic allocation
        cout << "Derived Constructor Allocated Memory\n";
    }

    ~Derived() {
        delete[] data;
        cout << "Derived Destructor Freed Memory\n";
    }
};

int main() {
    Base* ptr = new Derived(); // base pointer → derived object

    delete ptr; // ❌ only Base destructor called

    return 0;
}