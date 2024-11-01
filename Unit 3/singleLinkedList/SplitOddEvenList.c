//nhieu ban tu danh  sách cũ , lập chia thành 2 danh sách mới, thì sẽ bị thừa cái danh sách ban đầu , bị gấp đôi 
//bộ nhớ,nhưng thầy muốn là một con trỏ lẻ sẽ trỏ tới 1 con trỏ lẻ tieps theo, con trỏ chẵn sẽ trỏ tới con trỏ chẵn
// tiếp theo, và vẫn là danh sách liên kết đơn ấy, không cần bản sao nào khác.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertNode(Node* head, int value) {
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

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL.\n");
}

void splitList(Node* head, Node** evenList, Node** oddList) {
    Node* evenLast = NULL;
    Node* oddLast = NULL;

    Node* current = head;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (*evenList == NULL) {
                *evenList = current;
                evenLast = *evenList;
            } else {
                evenLast->next = current;
                evenLast = current;
            }
        } else {
            if (*oddList == NULL) {
                *oddList = current;
                oddLast = *oddList;
            } else {
                oddLast->next = current;
                oddLast= current;
            }
        }
        current = current->next;
    }

    if (evenLast != NULL) {
        evenLast->next = NULL;
    }

    if (oddLast != NULL) {
        oddLast->next = NULL;
    }
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* myList = NULL;
    Node* evenList = NULL;
    Node* oddList = NULL;

    int num;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num);
        myList = insertNode(myList, num);
    }

    printf("Original List: ");
    printList(myList);

    splitList(myList, &evenList , &oddList);

    printf("Even List: ");
    printList(evenList);

    printf("Odd List: ");
    printList(oddList);

    freeList(myList);

    return 0;
}
