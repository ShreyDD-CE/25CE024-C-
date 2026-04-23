#include <iostream>
using namespace std;

// Forward declaration
class Fahrenheit;

// ===============================
// 🔹 Celsius Class
// ===============================
class Celsius {
private:
    double temp;

public:
    Celsius(double t = 0) : temp(t) {}

    double getTemp() const { return temp; }

    // Conversion to Fahrenheit
    operator Fahrenheit();

    // Equality operator
    bool operator==(const Celsius& c) const {
        return temp == c.temp;
    }
};

// ===============================
// 🔹 Fahrenheit Class
// ===============================
class Fahrenheit {
private:
    double temp;

public:
    Fahrenheit(double t = 0) : temp(t) {}

    double getTemp() const { return temp; }

    // Conversion to Celsius
    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    // Equality operator
    bool operator==(const Fahrenheit& f) const {
        return temp == f.temp;
    }
};

// 🔁 Define conversion outside
Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

// ===============================
// 🔹 Queue Implementation
// ===============================
class TempQueue {
private:
    Celsius arr[100];
    int front, rear;

public:
    TempQueue() {
        front = rear = -1;
    }

    void enqueue(Celsius c) {
        if (rear == 99) {
            cout << "Queue Full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = c;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return;
        }
        cout << "Removed: " << arr[front].getTemp() << " C\n";
        front++;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i].getTemp() << " C ";
        }
        cout << endl;
    }
};

// ===============================
// 🔹 MAIN
// ===============================
int main() {

    // ===============================
    // 🔸 Conversion Demo
    // ===============================
    Celsius c1(25);
    Fahrenheit f1 = c1;  // auto conversion

    cout << "Celsius: " << c1.getTemp() << endl;
    cout << "Converted to Fahrenheit: " << f1.getTemp() << endl;

    // Reverse conversion
    Fahrenheit f2(77);
    Celsius c2 = f2;

    cout << "\nFahrenheit: " << f2.getTemp() << endl;
    cout << "Converted to Celsius: " << c2.getTemp() << endl;

    // ===============================
    // 🔸 Comparison
    // ===============================
    Celsius c3(25);

    if (c1 == c3)
        cout << "\nTemperatures are equal\n";
    else
        cout << "\nTemperatures are not equal\n";

    // ===============================
    // 🔸 Dynamic Queue (FIFO)
    // ===============================
    cout << "\n--- Queue Processing ---\n";

    TempQueue q;
    q.enqueue(Celsius(10));
    q.enqueue(Celsius(20));
    q.enqueue(Celsius(30));

    q.display();
    q.dequeue();
    q.display();

    // ===============================
    // 🔸 Static Array
    // ===============================
    cout << "\n--- Static Storage ---\n";

    Celsius arr[3] = {Celsius(15), Celsius(25), Celsius(35)};

    for (int i = 0; i < 3; i++) {
        Fahrenheit tempF = arr[i];
        cout << arr[i].getTemp() << " C = "
             << tempF.getTemp() << " F\n";
    }

    return 0;
}