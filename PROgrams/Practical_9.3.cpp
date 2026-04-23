#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    set<int> s;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x); // duplicates automatically ignored
    }

    // ===============================
    // 🔹 Display using iterators
    // ===============================
    cout << "\nUnique elements (sorted - using set):\n";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // ===============================
    // 🔹 Convert set → vector
    // ===============================
    vector<int> v(s.begin(), s.end());

    cout << "\nElements in vector:\n";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}