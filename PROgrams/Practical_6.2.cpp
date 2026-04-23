#include <iostream>
using namespace std;

// ===============================
// 🔹 Base Class: Person
// ===============================
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// ===============================
// 🔹 Intermediate Class: Employee
// ===============================
class Employee : public Person {
protected:
    int empID;

public:
    Employee(string n, int a, int id)
        : Person(n, a), empID(id) {}

    int getID() const {
        return empID;
    }

    void displayEmployee() const {
        displayPerson();
        cout << "Employee ID: " << empID << endl;
    }
};

// ===============================
// 🔹 Top Class: Manager
// ===============================
class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id), department(dept) {}

    void displayManager() const {
        displayEmployee();
        cout << "Department: " << department << endl;
        cout << "---------------------------\n";
    }
};

// ===============================
// 🔍 Search Manager by ID
// ===============================
Manager* findManager(Manager* arr[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (arr[i]->getID() == id)
            return arr[i];
    }
    return nullptr;
}

// ===============================
// 🔹 MAIN
// ===============================
int main() {
    int n;

    cout << "Enter number of managers: ";
    cin >> n;

    // ===============================
    // 🔸 Dynamic (Retrieval-based)
    // ===============================
    cout << "\n--- Dynamic Storage (Searchable) ---\n";

    Manager** managers = new Manager*[n];

    string name, dept;
    int age, id;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Manager " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> name;

        cout << "Age: ";
        cin >> age;

        cout << "Employee ID: ";
        cin >> id;

        cout << "Department: ";
        cin >> dept;

        managers[i] = new Manager(name, age, id, dept);
    }

    // Display all
    cout << "\n--- All Managers ---\n";
    for (int i = 0; i < n; i++) {
        managers[i]->displayManager();
    }

    // Search by ID
    int searchID;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;

    Manager* result = findManager(managers, n, searchID);

    if (result) {
        cout << "\nManager Found:\n";
        result->displayManager();
    } else {
        cout << "Manager not found.\n";
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        delete managers[i];
    }
    delete[] managers;

    // ===============================
    // 🔸 Static Storage
    // ===============================
    cout << "\n--- Static Storage ---\n";

    const int MAX = 3;
    Manager staticManagers[MAX] = {
        Manager("Shrey", 20, 101, "Tech"),
        Manager("Amit", 30, 102, "HR"),
        Manager("Neha", 28, 103, "Finance")
    };

    for (int i = 0; i < MAX; i++) {
        staticManagers[i].displayManager();
    }

    return 0;
}