#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single node in the linked list
struct Node {
    int data;          // Data field to store the value
    struct Node* next; // Pointer to the next node in the stack
};

// Global pointer to the top of the stack, initialized to NULL (empty stack)
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory overflow (Stack Overflow)\\n");
        return;
    }
    newNode->data = value; // Assign the value to the data field
    newNode->next = top;   // Link the new node to the current top node
    top = newNode;         // Update the top pointer to the new node
    printf("Pushed %d to stack\\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow (Stack is empty)\\n");
        return;
    }
    struct Node* temp = top; // Temporary pointer to the top node
    printf("Popped element is %d\\n", temp->data);
    top = top->next;         // Move the top pointer to the next node
    free(temp);              // Free the memory of the removed node
}

// Function to peek at the top element without removing it
int peek() {
    if (top == NULL) {
        printf("Stack is empty, cannot peek\\n");
        return -1; // Return a sentinel value or handle error
    }
    return top->data; // Return the value of the top node
}

// Function to display all elements in the stack
void display() {
    struct Node* ptr;
    if (top == NULL) {
        printf("Stack is empty\\n");
    } else {
        ptr = top;
        printf("Stack elements are: ");
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\\n");
    }
}

// Main function to run the program
int main() {
    int choice, value;
    printf("\\n--- Stack Implementation using Linked List ---\\n");
    do {
        printf("\\n1. Push\\n2. Pop\\n3. Peek\\n4. Display\\n5. Exit\\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is %d\\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\\n");
                break;
            default:
                printf("Invalid choice. Please try again.\\n");
        }
    } while (choice != 5);

    return 2;
}
