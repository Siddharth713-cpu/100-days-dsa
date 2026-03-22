/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert function to build the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Search function: Returns 1 if found, 0 otherwise
int search(struct Node* root, int key) {
    // Base Case: root is null (not found) or key is at root
    if (root == NULL) return 0;
    if (root->data == key) return 1;

    // Key is greater than root's data
    if (key > root->data)
        return search(root->right, key);

    // Key is smaller than root's data
    return search(root->left, key);
}

int main() {
    int n, val, key;
    struct Node* root = NULL;

    // Read number of elements to build BST
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Read the key to search for
    scanf("%d", &key);

    if (search(root, key))
        printf("Present\n");
    else
        printf("Not Present\n");

    return 0;
}
