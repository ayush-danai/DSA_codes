#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100
// Use INT_MAX to indicate an empty or non-existent node
#define EMPTY INT_MAX

// Function to initialize the tree array
void init_tree(int tree[], int size) {
    for (int i = 0; i < size; i++) {
        tree[i] = EMPTY;
    }
}

// Function to insert a value into the BST array representation iteratively
void insert(int tree[], int size, int element) {
    if (tree == NULL || element == EMPTY) return;

    int pos = 0;
    while (pos < size) {
        if (tree[pos] == EMPTY) {
            tree[pos] = element;
            return;
        } else if (element < tree[pos]) {
            pos = 2 * pos + 1; // Go to the left child index
        } else {
            pos = 2 * pos + 2; // Go to the right child index
        }
    }
    printf("Error: Tree array is full or insertion path invalid for element %d\n", element);
}

// Function for in-order traversal (Left, Root, Right)
void inorder_traversal(int tree[], int size, int index) {
    if (index >= size || tree[index] == EMPTY) return;

    inorder_traversal(tree, size, 2 * index + 1); // Left child
    printf("%d ", tree[index]);                  // Root
    inorder_traversal(tree, size, 2 * index + 2); // Right child
}

int main() {
    int tree[MAX_SIZE];
    const int tsize = MAX_SIZE;

    init_tree(tree, tsize);

    // Insert elements (BST property maintained for this insertion logic)
    insert(tree, tsize, 50);
    insert(tree, tsize, 30);
    insert(tree, tsize, 70);
    insert(tree, tsize, 20);
    insert(tree, tsize, 40);
    insert(tree, tsize, 60);
    insert(tree, tsize, 80);

    printf("In-order traversal of the binary tree: \n");
    // Start traversal from the root (index 0)
    inorder_traversal(tree, tsize, 0); 
    printf("\n");

    return 1;
}
