#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void displayList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteMin(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;
    struct Node* minNode = *head;
    struct Node* prev = NULL;

    while (current->next) {
        if (current->next->data < minNode->data) {
            minNode = current->next;
            prev = current;
        }
        current = current->next;
    }

    if (prev == NULL) {
        *head = minNode->next;
    } else {
        prev->next = minNode->next;
    }

    free(minNode);
}

void deleteMax(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;
    struct Node* maxNode = *head;
    struct Node* prev = NULL;

    while (current->next) {
        if (current->next->data > maxNode->data) {
            maxNode = current->next;
            prev = current;
        }
        current = current->next;
    }

    if (prev == NULL) {
        *head = maxNode->next;
    } else {
        prev->next = maxNode->next;
    }

    free(maxNode);
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
    int value;

    printf("Nhập số nguyên (Nhập 0 để kết thúc): ");
    scanf("%d", &value);

    while (value != 0) {
        insert(&head, value);
        printf("Nhập số nguyên tiếp theo (Nhập 0 để kết thúc): ");
        scanf("%d", &value);
    }

    printf("Danh sách ban đầu: ");
    displayList(head);

    deleteMin(&head);
    deleteMax(&head);

    printf("Danh sách sau khi xóa số lớn nhất và nhỏ nhất: ");
    displayList(head);

    deleteList(&head);

    printf("Danh sách sau khi xóa toàn bộ: ");
    displayList(head);

    return 0;
}
