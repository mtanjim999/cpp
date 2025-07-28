#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return index if element is found
        }
    }
    return -1; // Return -1 if element is not found
}

// Main function to take user input
int main() {
    int n, key;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n]; // Dynamic array size

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    int result = linearSearch(arr, n, key);

    if (result != -1) {
        cout << "Element found at index " << result << "." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

