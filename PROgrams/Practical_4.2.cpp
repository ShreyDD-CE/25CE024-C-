#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int xVal = 0, int yVal = 0) {
        x = xVal;
        y = yVal;
    }

    // 🔁 Chainable move function
    Point& move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        return *this;  // return current object reference
    }

    // Display
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// 🔹 Pass-by-reference using pointer
void updatePoint(Point* p, int dx, int dy) {
    p->move(dx, dy);  // modify original object
}

int main() {
    Point p(1, 2);

    cout << "Original Point: ";
    p.display();

    // ✅ Method chaining
    p.move(2, 3).move(-1, 4);

    cout << "After Chained Moves: ";
    p.display();

    // ✅ Pass-by-pointer (reference behavior)
    updatePoint(&p, 5, -2);

    cout << "After Pointer Update: ";
    p.display();

    return 0;
}
