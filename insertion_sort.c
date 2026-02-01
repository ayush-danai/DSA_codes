#include <stdio.h>

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    int i, key, j;
    // Start from the second element (index 1) as the first is assumed sorted
    for (i = 1; i < n; i++) {
        key = arr[i]; // Store the current element to be inserted
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than the key, 
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insert the key at its correct position
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array in ascending order: \n");
    printArray(arr, n);

    return 0;
}

