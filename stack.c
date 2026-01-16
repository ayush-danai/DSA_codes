#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Global pointer to the top of the stack
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int val) {
    // Dynamically allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow (Memory allocation error)\\n");
        return;
    }
    newNode->data = val; // Assign data
    newNode->next = top; // Link the new node to the current top
    top = newNode;       // Update the top pointer to the new node
    printf("%d pushed to stack\\n", val);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow (Stack is empty)\\n");
    } else {
        struct Node* temp = top;    // Temporary pointer to the top node
        printf("Popped element = %d\\n", temp->data);
        top = top->next;            // Move the top pointer to the next node
        free(temp);                 // Free the memory of the popped node
    }
}

// Function to display the elements in the stack
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

// Function to peek at the top element without removing it
void peek() {
    if (top == NULL) {
        printf("Stack is empty\\n");
    } else {
        printf("Top element is %d\\n", top->data);
    }
}

// Main function to drive the program with a menu
int main() {
    int choice, value;
    while (1) {
        printf("\\nMenu:\\n");
        printf("1. Push\\n");
        printf("2. Pop\\n");
        printf("3. Peek\\n");
        printf("4. Display\\n");
        printf("5. Exit\\n");
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
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\\n");
        }
    }
    return 1;
}
