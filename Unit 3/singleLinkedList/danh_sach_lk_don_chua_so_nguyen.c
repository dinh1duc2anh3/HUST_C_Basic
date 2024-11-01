#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to add a node to the beginning of the list
Node* push(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to print the list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to delete the entire list and free memory
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL; // Initialize an empty list

    int n, value;
    printf("Enter the number of elements you want to add to the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the value for element %d: ", i + 1);
        scanf("%d", &value);
        head = push(head, value); // Add a new value to the beginning of the list
    }

    printf("Your list:\n");
    printList(head);

    // Delete the list and free memory
    freeList(head);

    return 0;
}
