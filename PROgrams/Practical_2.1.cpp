#include <iostream>
#include <iomanip>  // For fixed precision
using namespace std;

class Rectangle {
private:
    double length;
    double width;
public:
    // Default constructor
    Rectangle() : length(0), width(0) {}
    
    // Parameterized constructor
    Rectangle(double l, double w) : length(l), width(w) {}
    
    // Setters for updates
    void setLength(double l) { length = l; }
    void setWidth(double w) { width = w; }
    
    // Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }
    
    // Calculations
    double area() const { return length * width; }
    double perimeter() const { return 2 * (length + width); }
    
    // Display
    void display() const {
        cout << fixed << setprecision(2);
        cout << "Length: " << length << ", Width: " << width 
             << ", Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
};

class PlotManager {
private:
    Rectangle plots[100];
    int totalPlots;
public:
    PlotManager() : totalPlots(0) {}
    
    void addRectangle() {
        if (totalPlots >= 100) {
            cout << "Max plots reached!" << endl;
            return;
        }
        double l, w;
        cout << "Enter length and width: ";
        cin >> l >> w;
        plots[totalPlots] = Rectangle(l, w);
        totalPlots++;
        cout << "Plot added." << endl;
    }
    
    void updateRectangle() {
        int index;
        cout << "Enter plot index to update (0-" << totalPlots-1 << "): ";
        cin >> index;
        if (index < 0 || index >= totalPlots) {
            cout << "Invalid index!" << endl;
            return;
        }
        double l, w;
        cout << "New length and width: ";
        cin >> l >> w;
        plots[index].setLength(l);
        plots[index].setWidth(w);
        cout << "Updated." << endl;
    }
    
    void displayAll() const {
        if (totalPlots == 0) {
            cout << "No plots." << endl;
            return;
        }
        cout << "\nAll Plots:" << endl;
        for (int i = 0; i < totalPlots; i++) {
            cout << "Plot " << i << ": ";
            plots[i].display();
        }
    }
    
    int getTotal() const { return totalPlots; }
};

int main() {
    PlotManager manager;
    int choice;
    while (true) {
        cout << "\n1. Add Plot\n2. Update Plot\n3. Display All\n4. Total Plots\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: manager.addRectangle(); break;
            case 2: manager.updateRectangle(); break;
            case 3: manager.displayAll(); break;
            case 4: cout << "Total plots: " << manager.getTotal() << endl; break;
            case 5: return 0;
            default: cout << "Invalid!" << endl;
        }
    }
    return 0;
}