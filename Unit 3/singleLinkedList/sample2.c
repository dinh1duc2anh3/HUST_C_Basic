/*single Linked List using both head and last ; 
function that use biến nội bộ , không phải biến toàn cục head và last*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------

typedef struct Node{
    int value;
    struct Node* next;
} Node;


Node* makeNode(int v){
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}

Node* insertFirst(Node** head, int v){
    Node* newNode = makeNode(v);
    if ((*head) == NULL) {
        *head = newNode;
        return *head;
    }
    newNode->next = *head;
    *head = newNode;
    return *head;
}

Node* insertLast(Node** head,Node **last, int v){
    Node* newNode = makeNode(v);
    if ((*head) == NULL ) {
        (*head) = newNode;
        *last = (*head);
        return (*head);
    }
    (*last)->next = newNode;
    (*last) = newNode;
    return (*head);
}

Node* insertLastRecursive(Node**head, int v){
    if (*head == NULL){
        return makeNode(v);
    }

    (*head)->next = insertLastRecursive( &((*head)->next) , v);
    return *head;
}

Node* removeNode(Node**head,Node ** last , int v){
    Node* p = *head;

    if (*head == NULL) return NULL;
    if ((*head)->value == v){
        Node* tmp = *head;
        *head = (*head)->next;
        free(tmp);


        if (*head == NULL) {
            *last = NULL;  // Update last when the list becomes empty
        }


        return (*head);
    }

    Node* pp = (*head);
    p = p->next;
    while (p != NULL){
        if (p->value == v){
            pp->next = p->next;
            free(p);
            return (*head);
        }
        pp = p;
        p = p->next;
    }
    return (*head);
}

Node* removeNodeRecursive(Node**head, int v){
    if ((*head) == NULL) return NULL;
    if ((*head)->value == v){
        Node* tmp = (*head);
        (*head) = (*head)->next;
        free(tmp);
        return (*head);
    }
    (*head)->next = removeNodeRecursive( &((*head)->next) , v);
    return (*head);
}

Node* removeAllRecursive(Node**head, int v){
    if ((*head) == NULL) return NULL;
    if ((*head)-> value == v){
        Node* tmp = (*head);
        (*head) = (*head)->next;
        free(tmp);
        (*head) = removeAllRecursive( &((*head)), v);
        return (*head);
    }
    (*head)->next = removeAllRecursive( &((*head)->next ), v);
    return (*head);
}

Node* reverse (Node **head, Node ** last){
    Node* p = (*head);
    Node* pp = NULL;
    Node* np = NULL;
    *last = p;  // Update last to the original head
    while (p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    *head = pp; // Update the head to point to the new head of the reversed list
    return pp;
}

void printList(Node* head){
    printf("list: ");
    Node* p = head;

    while (p != NULL){
        printf("%d ", p->value );
        p = p->next;
    }
    printf("\n");
}

void freeList(Node* head){
    Node* p = head;
    Node* np = NULL;
    while(p != NULL){
        np = p->next;
        free(p);
        p = np;
    }
}


Node* deleteMin(Node** head, Node** last){
    if (*head == NULL) return NULL;

    Node* current = *head;
    Node* minNode = *head;
    Node* prev = NULL;

    while (current->next != NULL){
        if (current->next->value < minNode->value ){
            minNode = current->next;
            prev = current;
        }
        current = current->next;
    }

    if (prev == NULL){
        *head = minNode->next;
    }

    if (minNode->next == NULL){
        *last = prev;
        (*last)->next = minNode->next;
    }

    free(minNode);
    return *head;
}

Node* deleteMax(Node** head, Node** last){
    if (*head == NULL) return NULL;

    Node* current = *head;
    Node* maxNode = *head;
    Node* prev = NULL;

    while (current->next != NULL){
        if (current->next->value > maxNode->value){
            prev = current;
            maxNode = current->next;
        }
        current = current->next;
    }

    if (prev == NULL){
        *head = maxNode->next;
    }

    if (maxNode->next == NULL){
        *last = prev;
        (*last)->next = maxNode->next;
    }
    free(maxNode);
    return *head;
}


//---------------------------------------------------------------------


void processCommand(){
    printf("-------------List of Commands-------------\n");
    printf("command \n");
    printf("insertFirst \n");
    printf("insertLast \n");
    printf("removeNode \n");
    printf("removeAll \n");
    printf("reverse \n");
    printf("deleteMin \n");
    printf("deleteMax \n");
    printf("printList \n");
    printf("exit \n");
    printf("---------------------------------------\n");
}

void processInsertFirst(Node** head){
    int num;
    scanf("%d",&num);
    insertFirst(head , num);
    printList(*head);
}

void processInsertLast(Node** head, Node** last){   
    int num;
    scanf("%d",&num);
    insertLast(head , last ,num);
    printList(*head);

}

void processRemoveAll(Node** head){
    int num;
    scanf("%d",&num);
    removeAllRecursive(head , num);
    printList(*head);

}

void processRemoveNode(Node** head , Node** last){
    int num;
    scanf("%d",&num);
    removeNode(head , last , num);
    printList(*head);

}

void processReverse(Node** head , Node** last){
    reverse(head , last);
    printList(*head);
}


void processDeleteMin(Node** head , Node** last){
    deleteMin(head , last);
    printList(*head);
}

void processDeleteMax(Node** head , Node** last){
    deleteMax(head , last);
    printList(*head);
}

//---------------------------------------------------------------------


int main(){
    Node* head = NULL;
    Node* last = NULL;
    processCommand();

    while (1) {
        char cmd[30];
        char c;
        scanf("%s",cmd);
        

        if (strcmp(cmd, "exit") == 0) break;
        else if (strcmp(cmd, "command") == 0) processCommand();
        else if (strcmp(cmd, "insertFirst") == 0) processInsertFirst(&head);
        else if (strcmp(cmd, "insertLast") == 0) processInsertLast(&head , &last);
        else if (strcmp(cmd, "removeNode") == 0) processRemoveNode(&head , &last);
        else if (strcmp(cmd, "removeAll") == 0) processRemoveAll(&head);
        else if (strcmp(cmd, "reverse") == 0) processReverse(&head , &last);
        else if (strcmp(cmd, "deleteMin") == 0) processDeleteMin(&head, &last);
        else if (strcmp(cmd, "deleteMax") == 0) processDeleteMax(&head, &last);
        else if (strcmp(cmd, "printList") == 0) printList(head);
    }

    
    freeList(head);
    return 0;


}

/*
command
insertFirst
insertLast
insertLastRecursive
removeNode
removeNodeRecursive
removeAll
reverse
printList
exit
*/