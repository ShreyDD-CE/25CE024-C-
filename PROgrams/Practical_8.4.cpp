#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string filename;
    ifstream file;

    // ===============================
    // 🔁 Retry mechanism for file open
    // ===============================
    while (true) {
        cout << "Enter file path (or type exit): ";
        cin >> filename;

        if (filename == "exit") {
            cout << "Exiting program.\n";
            return 0;
        }

        file.open(filename);

        if (file) break;

        cout << "Error: Cannot open file. Try again.\n";
        file.clear();
    }

    // ===============================
    // 🔹 Process file line-by-line
    // ===============================
    string line;
    int lineNumber = 0;

    cout << "\n--- Processing File ---\n";

    while (getline(file, line)) {
        lineNumber++;

        stringstream ss(line);
        double num, sum = 0;
        int count = 0;
        bool valid = true;

        // Read numbers from line
        while (ss >> num) {
            sum += num;
            count++;
        }

        // Check if parsing failed before end
        if (!ss.eof()) {
            valid = false;
        }

        if (valid && count > 0) {
            cout << "Line " << lineNumber
                 << " → Sum: " << sum
                 << ", Avg: " << (sum / count) << endl;
        } else {
            cout << "Line " << lineNumber
                 << " → Invalid data (skipped)\n";
        }
    }

    file.close();

    return 0;
}