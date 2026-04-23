#include <iostream>
using namespace std;

// 🔹 Display array
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 🔹 Find maximum
template <typename T>
T findMax(T arr[], int size) {
    T maxVal = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// 🔹 Reverse array
template <typename T>
void reverseArray(T arr[], int size) {
    int start = 0, end = size - 1;

    while (start < end) {
        T temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    // 🔸 Integer array
    int intArr[] = {10, 25, 3, 99, 7};
    int n1 = 5;

    cout << "Integer Array:\n";
    displayArray(intArr, n1);
    cout << "Max: " << findMax(intArr, n1) << endl;

    reverseArray(intArr, n1);
    cout << "Reversed: ";
    displayArray(intArr, n1);

    // 🔸 Float array
    float floatArr[] = {1.2, 5.6, 3.3, 9.8};
    int n2 = 4;

    cout << "\nFloat Array:\n";
    displayArray(floatArr, n2);
    cout << "Max: " << findMax(floatArr, n2) << endl;

    reverseArray(floatArr, n2);
    cout << "Reversed: ";
    displayArray(floatArr, n2);

    // 🔸 Character array
    char charArr[] = {'a', 'z', 'm', 'b'};
    int n3 = 4;

    cout << "\nCharacter Array:\n";
    displayArray(charArr, n3);
    cout << "Max: " << findMax(charArr, n3) << endl;

    reverseArray(charArr, n3);
    cout << "Reversed: ";
    displayArray(charArr, n3);

    return 0;
}