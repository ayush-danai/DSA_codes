#include <stdio.h>
#include <stdlib.h> // Required for malloc

// Define the structure for a tree node (uses linked list concept for children)
struct node {
    struct node *left;  // Pointer to the left child (acts as a link)
    int data;           // The value stored in the node
    struct node *right; // Pointer to the right child (acts as a link)
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for In-order Traversal (Left, Root, Right)
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for Pre-order Traversal (Root, Left, Right)
void preorderTraversal(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for Post-order Traversal (Left, Right, Root)
void postorderTraversal(struct node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function to demonstrate the tree
int main() {
    // Manually construct a simple binary tree
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5

    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("In-order Traversal: ");
    inorderTraversal(root); // Expected: 4 2 5 1 3
    printf("\n");

    printf("Pre-order Traversal: ");
    preorderTraversal(root); // Expected: 1 2 4 5 3
    printf("\n");

    printf("Post-order Traversal: ");
    postorderTraversal(root); // Expected: 4 5 2 3 1
    printf("\n");

    // In a real application, you would also need a function to free the allocated memory.

    return 1;
}
