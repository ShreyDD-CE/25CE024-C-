#include <iostream>
#include <ctime>
using namespace std;

// 🔁 Recursive function
int recursiveSum(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

// 🔄 Iterative function
int iterativeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    // Dynamic allocation
    int* arr = new int[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ⏱ Recursive timing
    clock_t startRec = clock();
    int recSum = recursiveSum(arr, n);
    clock_t endRec = clock();

    // ⏱ Iterative timing
    clock_t startItr = clock();
    int itrSum = iterativeSum(arr, n);
    clock_t endItr = clock();

    double timeRec = double(endRec - startRec) / CLOCKS_PER_SEC;
    double timeItr = double(endItr - startItr) / CLOCKS_PER_SEC;

    // Results
    cout << "\nRecursive Sum: " << recSum;
    cout << "\nIterative Sum: " << itrSum;

    cout << "\n\nExecution Time:";
    cout << "\nRecursive: " << timeRec << " seconds";
    cout << "\nIterative: " << timeItr << " seconds";

    // Cleanup
    delete[] arr;

    return 0;
}