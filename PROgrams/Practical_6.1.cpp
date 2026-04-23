#include <iostream>
using namespace std;

// 🔹 Base class
class Shape {
private:
    double radius;

public:
    void setRadius(double r) {
        if (r < 0) {
            cout << "Invalid radius. Setting to 0.\n";
            radius = 0;
        } else {
            radius = r;
        }
    }

    double getRadius() const {
        return radius;
    }
};

// 🔹 Derived class
class Circle : public Shape {
public:
    double calculateArea() const {
        double r = getRadius();
        return 3.14159 * r * r;
    }
};

int main() {
    int n;

    cout << "Enter number of circles: ";
    cin >> n;

    // ===============================
    // 🔸 Dynamic Approach
    // ===============================
    cout << "\n--- Dynamic Allocation ---\n";

    Circle* dynCircles = new Circle[n];

    for (int i = 0; i < n; i++) {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        dynCircles[i].setRadius(r);
    }

    cout << "\nAreas (Dynamic):\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1
             << " Area = " << dynCircles[i].calculateArea()
             << endl;
    }

    delete[] dynCircles;

    // ===============================
    // 🔸 Static Approach
    // ===============================
    cout << "\n--- Static Allocation ---\n";

    const int MAX = 5;
    Circle staticCircles[MAX];

    int count;
    cout << "Enter number of circles (max 5): ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        staticCircles[i].setRadius(r);
    }

    cout << "\nAreas (Static):\n";
    for (int i = 0; i < count; i++) {
        cout << "Circle " << i + 1
             << " Area = " << staticCircles[i].calculateArea()
             << endl;
    }

    return 0;
}