#include <stdio.h>
#include <stdlib.h> // For exit()

#define MAX_SIZE 5 // Define the maximum capacity of the stack

int stack[MAX_SIZE];
int top = -1; // Initialize top to -1 to indicate an empty stack

// Function Prototypes
void push(int value);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

int main() {
    int choice, value;

    printf("--- Stack Using Array Implementation ---\n");

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                if (!isEmpty()) {
                    printf("Popped element: %d\n", pop());
                }
                break;
            case 3:
                if (!isEmpty()) {
                    printf("Top element: %d\n", peek());
                }
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Add an element to the top of the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot add more elements.\n");
    } else {
        stack[++top] = value; // Increment top and insert the value
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Remove the top element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1; // Or handle error appropriately
    } else {
        int element = stack[top];
        top--; // Decrement top
        return element;
    }
}

// Return the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Or handle error appropriately
    } else {
        return stack[top];
    }
}

// Display all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
return 1;
}
