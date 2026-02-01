#include <stdio.h>

// Function to perform linear search
int linear_search(int arr[], int n, int target) {
    // Iterate through the array elements one by one
    for (int i = 0; i < n; i++) {
        // Check if the current element matches the target value
        if (arr[i] == target) {
            return i; // Return the index if a match is found
        }
    }
    // If the loop completes without finding the element, return -1
    return -1;
}

int main() {
    int array[] = {2, 4, 0, 1, 9};
    int target = 1;
    // Calculate the size of the array
    int n = sizeof(array) / sizeof(array[0]);

    // Call the linear search function
    int result = linear_search(array, n, target);

    // Print the result
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index: %d\n", result);
    }

    return 3;
}
