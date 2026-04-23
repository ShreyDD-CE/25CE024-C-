#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

// 🔹 Convert to lowercase (optional but useful)
string toLower(string s) {
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z')
            c = c + 32;
    }
    return s;
}

int main() {
    string sentence;

    cout << "Enter a sentence:\n";
    getline(cin, sentence);

    map<string, int> freq;

    stringstream ss(sentence);
    string word;

    // Extract words
    while (ss >> word) {
        word = toLower(word); // optional normalization
        freq[word]++;         // increase count
    }

    // Display results
    cout << "\n--- Word Frequencies ---\n";
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}