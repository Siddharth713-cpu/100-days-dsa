/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key;
    if (scanf("%d", &n) != 1) return 0;

    struct Node *head = NULL, *tail = NULL;

    // 1. Create the Linked List
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Read the key to delete
    scanf("%d", &key);

    // 2. Deletion Logic
    struct Node *temp = head, *prev = NULL;

    // Case 1: The head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next; 
        free(temp);        
    } else {
        // Case 2: Search for the key
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key was found, unlink the node
        if (temp != NULL) {
            prev->next = temp->next;
            free(temp);
        }
    }

    // 3. Print the Result
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
