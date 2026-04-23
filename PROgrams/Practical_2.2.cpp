#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Student {
private:
    int rollNo;
    char name[50];
    int marks[3];  // Three subjects
public:
    // Default constructor (for testing)
    Student() {
        rollNo = 0;
        strcpy(name, "Test Student");
        marks[0] = marks[1] = marks[2] = 70;  // Default marks
    }
    
    // Parameterized constructor (user input)
    Student(int r, const char* n, int m1, int m2, int m3) {
        rollNo = r;
        strcpy(name, n);
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }
    
    // Input method
    void inputDetails() {
        cout << "Roll No: "; cin >> rollNo;
        cout << "Name: "; cin.ignore(); cin.getline(name, 50);
        cout << "Marks (3 subjects): ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }
    
    // Calculate average
    double average() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }
    
    // Display
    void display() const {
        cout << fixed << setprecision(2);
        cout << "Roll: " << rollNo << ", Name: " << name 
             << ", Marks: " << marks[0] << "," << marks[1] << "," << marks[2]
             << ", Average: " << average() << endl;
    }
    
    // Get roll for reference
    int getRoll() const { return rollNo; }
};

class StudentManager {
private:
    Student students[50];
    int totalStudents;
public:
    StudentManager() : totalStudents(0) {}
    
    void addDefault() {
        if (totalStudents >= 50) {
            cout << "Max students reached!" << endl;
            return;
        }
        students[totalStudents++] = Student();  // Default
        cout << "Default student added." << endl;
    }
    
    void addUserInput() {
        if (totalStudents >= 50) {
            cout << "Max students reached!" << endl;
            return;
        }
        students[totalStudents].inputDetails();
        totalStudents++;
        cout << "Student added." << endl;
    }
    
    void displayAll() const {
        if (totalStudents == 0) {
            cout << "No students." << endl;
            return;
        }
        cout << "\nAll Students:" << endl;
        for (int i = 0; i < totalStudents; i++) {
            students[i].display();
        }
    }
};

int main() {
    StudentManager mgr;
    int choice;
    cout << "Demo: Adding default and user students..." << endl;
    mgr.addDefault();  // Test default
    mgr.addUserInput();  // User input
    
    while (true) {
        cout << "\n1. Add Default\n2. Add User Input\n3. Display All\n4. Exit\nChoice: ";
        cin >> choice;
        if (choice == 4) break;
        switch (choice) {
            case 1: mgr.addDefault(); break;
            case 2: mgr.addUserInput(); break;
            case 3: mgr.displayAll(); break;
            default: cout << "Invalid!" << endl;
        }
    }
    return 0;
}