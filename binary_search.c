#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    // Continue searching as long as the search space is valid
    while (low <= high) {
        // Calculate the middle index. Using this formula prevents potential integer overflow.
        int mid = low + (high - low) / 2;

        // Check if the target is present at the middle
        if (arr[mid] == target) {
            return mid; // Target found, return its index
        }

        // If the target is greater than the middle element, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        }
        // If the target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    // If the loop finishes without finding the target, it means the element is not present
    return -1; // Target not found
}

int main() {
    int numbers[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72}; // Array must be sorted
    int target = 23;
    // Calculate the size of the array
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Perform the binary search
    int index = binarySearch(numbers, n, target);

    // Print the result
    if (index != -1) {
        printf("Element %d found at index: %d\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 1;
}
