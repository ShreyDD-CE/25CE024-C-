#include <iostream>
#include <iomanip>
using namespace std;

// 🔹 User-defined manipulator
ostream& currency(ostream& out) {
    out << "₹ ";
    return out;
}

struct Student {
    string name;
    int marks;
    double fees;
};

int main() {
    Student s[3] = {
        {"Shrey", 92, 15000.5},
        {"Amit", 85, 12000},
        {"Neha", 78, 13550.75}
    };

    cout << setfill('=') << setw(50) << "" << endl;

    cout << setfill(' ') 
         << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(20) << "Fees" << endl;

    cout << setfill('-') << setw(50) << "" << endl;

    // Display data
    for (int i = 0; i < 3; i++) {
        cout << setfill(' ')
             << setw(15) << s[i].name
             << setw(10) << s[i].marks
             << setw(10) << currency   // 👈 custom manipulator
             << fixed << setprecision(2)
             << s[i].fees
             << endl;
    }

    cout << setfill('=') << setw(50) << "" << endl;

    return 0;
}