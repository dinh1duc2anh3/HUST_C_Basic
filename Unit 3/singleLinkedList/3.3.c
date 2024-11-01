#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (!(*head) || (*head)->data > value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteList(struct Node** head) {
    while (*head) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("1. insert\n");
        printf("2. display list\n");
        printf("3. delete List\n");
        printf("4. exit\n");
        printf("pick choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter number: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("List: ");
                displayList(head);
                break;
            case 3:
                deleteList(&head);
                printf("List has been deleted.\n");
                break;
            case 4:
                printf("Exited program.\n");
                break;
            default:
                printf("Retry.\n");
        }

    } while (choice != 4);

    return 0;
}
