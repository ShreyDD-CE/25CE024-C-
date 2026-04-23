#include <iostream>
#include <string>
using namespace std;

// Convert string to lowercase
string toLowerCase(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
    return s;
}

// Check if character is letter or digit
bool isValidChar(char c) {
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

int main() {
    string paragraph;

    cout << "Enter paragraph:\n";
    getline(cin, paragraph);

    paragraph = toLowerCase(paragraph);

    const int MAX = 1000;
    string words[MAX];
    int count[MAX] = {0};
    int uniqueCount = 0;

    string currentWord = "";

    // Extract words manually
    for (int i = 0; i <= paragraph.length(); i++) {
        if (i < paragraph.length() && isValidChar(paragraph[i])) {
            currentWord += paragraph[i];
        } else {
            if (currentWord != "") {
                // Check if word already exists
                bool found = false;

                for (int j = 0; j < uniqueCount; j++) {
                    if (words[j] == currentWord) {
                        count[j]++;
                        found = true;
                        break;
                    }
                }

                // New word
                if (!found) {
                    words[uniqueCount] = currentWord;
                    count[uniqueCount] = 1;
                    uniqueCount++;
                }

                currentWord = "";
            }
        }
    }

    // Display results
    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < uniqueCount; i++) {
        cout << words[i] << " : " << count[i] << endl;
    }

    return 0;
}