#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

// 🔹 Display function
void display(const vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// 🔹 Manual reversal using iterators
void manualReverse(vector<int>& v) {
    auto start = v.begin();
    auto end = v.end() - 1;

    while (start < end) {
        // swap values
        int temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Original
    cout << "\nOriginal Vector: ";
    display(v);

    // ===============================
    // 🔸 Method 1: std::reverse
    // ===============================
    vector<int> v1 = v; // copy

    reverse(v1.begin(), v1.end());

    cout << "Reversed (std::reverse): ";
    display(v1);

    // ===============================
    // 🔸 Method 2: Manual reversal
    // ===============================
    vector<int> v2 = v; // copy

    manualReverse(v2);

    cout << "Reversed (manual iterators): ";
    display(v2);

    return 0;
}