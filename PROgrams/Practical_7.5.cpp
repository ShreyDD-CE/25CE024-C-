#include <iostream>
using namespace std;

// ===============================
// 🔹 Abstract Base Class
// ===============================
class Grading {
protected:
    string name;
    double marks;

public:
    Grading(string n, double m) : name(n), marks(m) {}

    // Pure virtual function
    virtual char computeGrade() const = 0;

    // Virtual display
    virtual void display() const {
        cout << "Name: " << name
             << " | Marks: " << marks
             << " | Grade: " << computeGrade() << endl;
    }

    virtual ~Grading() {}
};

// ===============================
// 🔹 Undergraduate Class
// ===============================
class Undergraduate : public Grading {
public:
    Undergraduate(string n, double m) : Grading(n, m) {}

    char computeGrade() const override {
        if (marks >= 85) return 'A';
        else if (marks >= 70) return 'B';
        else if (marks >= 55) return 'C';
        else if (marks >= 40) return 'D';
        else return 'F';
    }
};

// ===============================
// 🔹 Postgraduate Class
// ===============================
class Postgraduate : public Grading {
public:
    Postgraduate(string n, double m) : Grading(n, m) {}

    char computeGrade() const override {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 60) return 'C';
        else if (marks >= 50) return 'D';
        else return 'F';
    }
};

// ===============================
// 🔹 MAIN
// ===============================
int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    // ===============================
    // 🔸 Dynamic Collection
    // ===============================
    Grading** students = new Grading*[n];

    string name;
    double marks;
    int type;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> name;

        cout << "Marks: ";
        cin >> marks;

        cout << "Type (1: Undergraduate, 2: Postgraduate): ";
        cin >> type;

        if (type == 1)
            students[i] = new Undergraduate(name, marks);
        else
            students[i] = new Postgraduate(name, marks);
    }

    // Display all
    cout << "\n--- Student Grades ---\n";
    for (int i = 0; i < n; i++) {
        students[i]->display(); // polymorphism
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        delete students[i];
    }
    delete[] students;

    // ===============================
    // 🔸 Static Collection
    // ===============================
    cout << "\n--- Static Example ---\n";

    Grading* staticStudents[2];
    staticStudents[0] = new Undergraduate("Shrey", 82);
    staticStudents[1] = new Postgraduate("Neha", 88);

    for (int i = 0; i < 2; i++) {
        staticStudents[i]->display();
        delete staticStudents[i];
    }

    return 0;
}