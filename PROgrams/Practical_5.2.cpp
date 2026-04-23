#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Check if character is part of a word
bool isValidChar(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

int main() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ifstream file(filename);

    // ❌ Error handling
    if (!file) {
        cout << "Error: Could not open file.\n";
        return 1;
    }

    string line;
    int lineCount = 0, wordCount = 0, charCount = 0;

    // Read file line by line
    while (getline(file, line)) {
        lineCount++;

        for (int i = 0; i < line.length(); i++) {
            charCount++; // count every character

            // Word detection
            if (isValidChar(line[i])) {
                if (i == 0 || !isValidChar(line[i - 1])) {
                    wordCount++;
                }
            }
        }
    }

    file.close();

    // Display results
    cout << "\n--- File Statistics ---\n";
    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << charCount << endl;

    return 0;
}