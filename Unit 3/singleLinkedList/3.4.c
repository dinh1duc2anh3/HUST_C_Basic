#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* insertNode(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end of the list
    current->next = newNode;

    // Return the head of the modified list
    return head;
}


void printList(Node* head){
    Node* current = head;
    while (current != NULL){
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL.\n");
}


void splitList(Node* head, Node** evenList, Node** oddList) {
    Node* evenHead = NULL;
    Node* oddHead = NULL;

    Node* current = head;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (*evenList == NULL) {
                *evenList = current;
                evenHead = *evenList;
            } else {
                (*evenList)->next = current;
                *evenList = (*evenList)->next;
            }
        } else {
            if (*oddList == NULL) {
                *oddList = current;
                oddHead = *oddList;
            } else {
                (*oddList)->next = current;
                *oddList = (*oddList)->next;
            }
        }
        current = current->next;
    }

    if (evenHead != NULL) {
        (*evenList)->next = NULL;
    }

    if (oddHead != NULL) {
        (*oddList)->next = NULL;
    }
}


void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* myList = NULL;
    struct Node* evenList = NULL;
    struct Node* oddList = NULL;

    // srand(time(NULL));
    // // Chèn 5 số nguyên ngẫu nhiên vào danh sách
    // for (int i = 0; i < 5; ++i) {
    //     int value = rand() % 100; // Số nguyên ngẫu nhiên từ 0 đến 99
    //     myList = insertNode(myList, value);
    // }
    int num;
    for (int i = 0; i < 5; i++){
        scanf("%d" , &num);
        insertNode(myList , num);
    }

    // In ra danh sách
    printf("Danh sach: ");
    printList(myList);

    // Tách danh sách thành 2 danh sách chẵn và lẻ
    splitList(myList, &evenList, &oddList);

    // In ra danh sách chẵn và lẻ
    printf("Danh sach chan: ");
    printList(evenList);
    printf("Danh sach le: ");
    printList(oddList);

    // Giải phóng bộ nhớ của 2 danh sách
    freeList(myList);
    freeList(evenList);
    freeList(oddList);

    return 0;
}
