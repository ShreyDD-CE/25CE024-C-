#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    // Resize function
    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

public:
    // Constructor
    DynamicArray(int cap = 2) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Insert at end
    void insert(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    // Delete at position
    void remove(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!\n";
            return;
        }

        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Display array
    void display() const {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray da;

    da.insert(10);
    da.insert(20);
    da.insert(30);
    da.insert(40);

    da.display();

    da.remove(1); // delete element at index 1

    da.display();

    da.insert(50);
    da.insert(60);

    da.display();

    return 0;
}