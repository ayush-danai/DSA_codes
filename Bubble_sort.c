#include <stdio.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Outer loop for passes through the array (n-1 passes)
    for (i = 0; i < n - 1; i++) {
        // Inner loop for comparisons and swaps in each pass
        for (j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements and swap if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements

    printf("Original array: ");
    printArray(arr, n);

    bubbleSort(arr, n); // Call the bubble sort function

    printf("Sorted array: ");
    printArray(arr, n);

    return 1;
}
