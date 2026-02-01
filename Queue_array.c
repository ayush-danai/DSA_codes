#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum capacity of the queue

int queue_array[MAX_SIZE];
int front = -1; // Pointer to the first element
int rear = -1;  // Pointer to the last element

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1 || front > rear)
        return 1; // True, queue is empty
    else
        return 0; // False, queue is not empty
}

// Function to check if the queue is full
int isFull() {
    if (rear == MAX_SIZE - 1)
        return 1; // True, queue is full
    else
        return 0; // False, queue is not full
}

// Function to add an element to the queue (enqueue)
void enqueue(int element) {
    if (isFull()) {
        printf("Queue Overflow: Cannot insert %d, queue is full.\n", element);
    } else {
        if (front == -1)
            front = 0; // Set front to 0 when the first element is inserted
        rear++;
        queue_array[rear] = element;
        printf("Inserted %d into the queue.\n", element);
    }
}

// Function to remove an element from the queue (dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow: Cannot delete, queue is empty.\n");
    } else {
        int removed_element = queue_array[front];
        front++;

        // If the queue becomes empty after deletion, reset front and rear
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        printf("Removed element: %d\n", removed_element);
    }
}

// Function to display all elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate queue operations
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    dequeue();
    display();

    enqueue(50);
    enqueue(60); // This will cause a Queue Overflow if MAX_SIZE is 5

    display();

    return 6;
}
