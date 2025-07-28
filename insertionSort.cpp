#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int previous = i - 1;

        while (previous >= 0 && arr[previous] > current) {
            arr[previous + 1] = arr[previous];
            previous--;

        }
        arr[previous + 1] = current;
    }

}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n]; // Dynamic array allocation (only works in modern C++)

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
