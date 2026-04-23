#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    // ✅ Default constructor (fixes your error)
    Employee() {
        name = "Unknown";
        basicSalary = 0;
        bonus = 2000; // default bonus
    }

    // ✅ Parameterized constructor
    Employee(string n, double salary, double b = 2000) {
        name = n;

        if (salary < 0) {
            cout << "Invalid salary. Setting to 0.\n";
            basicSalary = 0;
        } else {
            basicSalary = salary;
        }

        if (b < 0) {
            cout << "Invalid bonus. Using default (2000).\n";
            bonus = 2000;
        } else {
            bonus = b;
        }
    }

    // ✅ Inline function
    inline double calculateTotalSalary() const {
        return basicSalary + bonus;
    }

    // Display details
    void display() const {
        cout << "\n--- Employee Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculateTotalSalary() << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    // ✅ Dynamic array (now works because default constructor exists)
    Employee* emp = new Employee[n];

    string name;
    double salary, bonus;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for employee " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> name;

        cout << "Basic Salary: ";
        cin >> salary;

        cout << "Enter bonus (-1 for default): ";
        cin >> bonus;

        if (bonus == -1)
            emp[i] = Employee(name, salary);        // default bonus
        else
            emp[i] = Employee(name, salary, bonus); // custom bonus
    }

    // Display all employees
    for (int i = 0; i < n; i++) {
        emp[i].display();
    }

    // Free memory
    delete[] emp;

    return 0;
}