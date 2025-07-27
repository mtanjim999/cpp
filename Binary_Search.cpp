#include <iostream>
#include <algorithm> // For sorting the array
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid; // Element found

        if (arr[mid] < key)
            left = mid + 1; // Search in the right half
        else
            right = mid - 1; // Search in the left half
    }
    return -1; // Element not found
}

// Main function to take user input
int main() {
    int n, key;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n]; // Dynamic array

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sorting the array (Binary search works only on sorted data)
    sort(arr, arr + n);

    cout << "Enter the element to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        cout << "Element found at index " << result << "." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
