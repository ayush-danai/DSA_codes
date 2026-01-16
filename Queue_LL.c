#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

// Define the structure for a single node in the linked list
struct Node {
    int data;          // Data stored in the node
    struct Node* next; // Pointer to the next node
};

// Global pointers for the front and rear of the queue, initialized to NULL for an empty queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add an element to the queue (enqueue operation)
void enqueue(int value) {
    // Create a new node and allocate memory dynamically
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow! Out of memory.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, the new node is both the front and rear
    if (rear == NULL) {
        front = newNode;
        rear = newNode;
        return;
    }

    // Otherwise, add the new node to the end and update the rear pointer
    rear->next = newNode;
    rear = newNode;
}

// Function to remove an element from the queue (dequeue operation)
void dequeue() {
    // Check if the queue is empty (underflow condition)
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    // Store the front node in a temporary pointer
    struct Node* temp = front;
    printf("Dequeued element: %d\n", temp->data);

    // Move the front pointer to the next node
    front = front->next;

    // If the queue becomes empty after deletion, update the rear pointer to NULL
    if (front == NULL) {
        rear = NULL;
    }

    // Free the memory of the removed node
    free(temp);
}

// Function to display the elements in the queue
void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate queue operations
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Output: Queue elements: 10 -> 20 -> 30 -> NULL

    dequeue(); // Output: Dequeued element: 10
    display(); // Output: Queue elements: 20 -> 30 -> NULL

    dequeue(); // Output: Dequeued element: 20
    dequeue(); // Output: Dequeued element: 30
    dequeue(); // Output: Queue Underflow! Queue is empty.

    return 1;
}
