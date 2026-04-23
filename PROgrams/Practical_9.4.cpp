        #include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<string, vector<string>> directory;
    int choice;

    do {
        cout << "\n--- Directory Management ---\n";
        cout << "1. Add Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string folder;
            cout << "Enter folder name: ";
            cin >> folder;

            if (directory.find(folder) == directory.end()) {
                directory[folder] = vector<string>();
                cout << "Folder added.\n";
            } else {
                cout << "Folder already exists!\n";
            }
        }

        else if (choice == 2) {
            string folder, file;
            cout << "Enter folder name: ";
            cin >> folder;

            if (directory.find(folder) != directory.end()) {
                cout << "Enter file name: ";
                cin >> file;

                directory[folder].push_back(file);
                cout << "File added to folder.\n";
            } else {
                cout << "Folder does not exist!\n";
            }
        }

        else if (choice == 3) {
            cout << "\n--- Directory Contents ---\n";

            for (auto it = directory.begin(); it != directory.end(); ++it) {
                cout << "Folder: " << it->first << endl;

                vector<string>& files = it->second;

                if (files.empty()) {
                    cout << "  (No files)\n";
                } else {
                    for (auto fit = files.begin(); fit != files.end(); ++fit) {
                        cout << "  - " << *fit << endl;
                    }
                }
            }
        }

    } while (choice != 4);

    return 0;
}