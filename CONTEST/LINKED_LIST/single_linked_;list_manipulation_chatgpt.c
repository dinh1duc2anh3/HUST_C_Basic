#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void addLast(struct LinkedList* list, int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;

    if (!list->head) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void addFirst(struct LinkedList* list, int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = list->head;
    list->head = newNode;
}

void addAfter(struct LinkedList* list, int keyU, int keyV) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = keyU;

    struct Node* current = list->head;
    while (current) {
        if (current->key == keyV) {
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
        current = current->next;
    }
}

void addBefore(struct LinkedList* list, int keyU, int keyV) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = keyU;

    if (list->head->key == keyV) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    struct Node* current = list->head;
    while (current->next) {
        if (current->next->key == keyV) {
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
        current = current->next;
    }
}

void removeKey(struct LinkedList* list, int key) {
    if (!list->head) {
        return;
    }

    if (list->head->key == key) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    struct Node* current = list->head;
    while (current->next) {
        if (current->next->key == key) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

void reverseList(struct LinkedList* list) {
    struct Node* prev = NULL;
    struct Node* current = list->head;

    while (current) {
        struct Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    list->head = prev;
}

void printList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current) {
        printf("%d ", current->key);
        current = current->next;
    }
}

int main() {
    struct LinkedList linkedList;
    linkedList.head = NULL;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int key;
        scanf("%d", &key);
        addLast(&linkedList, key);
    }

    while (1) {
        char command[20];
        scanf("%s", command);

        if (command[0] == '#') {
            break;
        }

        int key, keyU, keyV;
        if (command[0] == 'a') {
            scanf("%d", &key);
        } else if (command[0] == 'r') {
            scanf("%d", &key);
        } else if (command[0] == 'a' && command[3] == 't') {
            scanf("%d %d", &keyU, &keyV);
        } else if (command[0] == 'a' && command[3] == 'b' && command[6] == 'e') {
            scanf("%d %d", &keyU, &keyV);
        }

        if (command[0] == 'a' && command[3] == 'l') {
            addLast(&linkedList, key);
        } else if (command[0] == 'a' && command[3] == 'f') {
            addFirst(&linkedList, key);
        } else if (command[0] == 'a' && command[3] == 'a' && command[5] == 't') {
            addAfter(&linkedList, keyU, keyV);
        } else if (command[0] == 'a' && command[3] == 'b' && command[6] == 'e') {
            addBefore(&linkedList, keyU, keyV);
        } else if (command[0] == 'r' && command[1] == 'e') {
            removeKey(&linkedList, key);
        } else if (command[0] == 'r' && command[1] == 'e' && command[2] == 'v') {
            reverseList(&linkedList);
        }
    }

    printList(&linkedList);

    return 0;
}
