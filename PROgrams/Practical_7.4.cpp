#include <iostream>
using namespace std;

// ===============================
// 🔹 Base Class
// ===============================
class Shape {
public:
    virtual double area() const = 0; // pure virtual

    virtual void display() const {
        cout << "Shape Area: " << area() << endl;
    }

    virtual ~Shape() {} // virtual destructor
};

// ===============================
// 🔹 Rectangle Class
// ===============================
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    void display() const override {
        cout << "Rectangle Area: " << area() << endl;
    }
};

// ===============================
// 🔹 Circle Class
// ===============================
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        cout << "Circle Area: " << area() << endl;
    }
};

// ===============================
// 🔹 MAIN
// ===============================
int main() {

    int n;

    cout << "Enter number of shapes: ";
    cin >> n;

    // ===============================
    // 🔸 Dynamic Storage
    // ===============================
    cout << "\n--- Dynamic Storage ---\n";

    Shape** shapes = new Shape*[n];

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "\n1. Rectangle  2. Circle\nChoose shape: ";
        cin >> choice;

        if (choice == 1) {
            double l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            shapes[i] = new Rectangle(l, w);
        } else {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            shapes[i] = new Circle(r);
        }
    }

    cout << "\n--- Areas (Polymorphism) ---\n";
    for (int i = 0; i < n; i++) {
        shapes[i]->display(); // runtime polymorphism
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        delete shapes[i];
    }
    delete[] shapes;

    // ===============================
    // 🔸 Static Storage
    // ===============================
    cout << "\n--- Static Storage ---\n";

    Shape* staticShapes[3];

    staticShapes[0] = new Rectangle(4, 5);
    staticShapes[1] = new Circle(3);
    staticShapes[2] = new Rectangle(2, 6);

    for (int i = 0; i < 3; i++) {
        staticShapes[i]->display();
        delete staticShapes[i];
    }

    return 0;
}