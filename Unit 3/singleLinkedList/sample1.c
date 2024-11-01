/*single Linked List using  head , last , 
function that use Global Variables : head , last*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------


typedef struct Node{
    int value;
    struct Node* next;
} Node;

Node * head = NULL;
Node * last = NULL;


Node* makeNode (int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p ->value = v;
    p->next = NULL;
    return p;
}

Node* insertFirst(int v){
    Node* newNode = makeNode(v);
    if (head == NULL){
        head = newNode;
        return head;
    }

    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertLast(int v){
    Node* newNode = makeNode(v);

    if (head == NULL){
        head = newNode;
        last = newNode;
        return head;
    }

    last->next = newNode;
    last = newNode;
    return head;
}

Node* insertLastRecursive (Node** head, int v){
    if (head == NULL){
        return makeNode(v);
    }
    (*head)->next = insertLastRecursive( &((*head)->next) , v);
    return *head;
}


Node* removeNode(int v){

    if (head == NULL) return NULL;
    if (head->value == v){
        Node* tmp = head;
        head = head->next;
        free(tmp);

        if (head == NULL){
            last = NULL;
        }
        return head;

    }

    Node* p =head;    
    Node * pp = head;
    p = p->next;
    while (p!= NULL){
        if (p->value == v){
            pp->next = p->next;
            free(p);
            return head;
        }
        pp = p;
        p = p->next;
    }
    return head;
}

Node* removeNodeRecursive(Node** head,int v){
    if (*head==NULL) return NULL;
    if ((*head)->value == v){
        Node* tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return *head;
    }

    (*head)->next = removeNodeRecursive( &((*head)->next), v);
    return *head;
}

Node* removeAllRecursive(Node** head,int v){
    if ((*head) ==NULL) return NULL;
    if ((*head)->value == v){
        Node* tmp =*head;
        *head=(*head)->next;
        free(tmp);
        *head = removeAllRecursive(head,v);
        return *head;
    }
    (*head)->next = removeAllRecursive( &((*head)->next),v);
    return *head;
}

Node* reverse(){
    Node* p = head;
    Node* pp = NULL;
    Node* np = NULL;
    last = p; // Update last to the original head
    while (p != NULL){
        np = p->next;
        p->next  = pp;
        pp = p;
        p = np;
    }

    head = pp;// Update the head to point to the new head of the reversed list
    return pp;

}

Node* deleteMin(){
    if (head == NULL) return NULL;

    Node* current = head;
    Node* minNode = head;
    Node* prev = NULL;

    while (current->next != NULL){
        if (current->next->value < minNode->value ){
            minNode = current->next;
            prev = current;
        }
        current = current->next;
    }

    if (prev == NULL){
        head = minNode->next;
    }

    if (minNode->next == NULL){
        last = prev;
        last->next = minNode->next;
    }

    free(minNode);
    return head;
}

Node* deleteMax(){
    if (head == NULL) return NULL;

    Node* current = head;
    Node* maxNode = head;
    Node* prev = NULL;

    while (current->next != NULL){
        if (current->next->value > maxNode->value){
            prev = current;
            maxNode = current->next;
        }
        current = current->next;
    }

    if (prev == NULL){
        head = maxNode->next;
    }

    if (maxNode->next == NULL){
        last = prev;
        last->next = maxNode->next;
    }
    free(maxNode);
    return head;
}

int count(){
    Node* p = head;
    int cnt = 0;
    while (p != NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}

int countRecursive(Node* head){
    if (head == NULL) return 0;
    return 1 + countRecursive(head->next);
}


void printList(){
    
    printf("list: ");
    Node* p = head;

    while (p != NULL){
        printf("%d ", p->value );
        p = p->next;
    }
    printf("\n");

}

void freeList(){
    Node* p = head;
    Node* np = NULL;
    while(p != NULL){
        np = p->next;
        free(p);
        p = np;
    }
}

//---------------------------------------------------------------------


void processCommand(){
    printf("-------------List of Commands-------------\n");
    printf("command \n");
    printf("insertFirst \n");
    printf("insertLast \n");
    printf("remove \n");
    printf("removeAll \n");
    printf("reverse \n");
    printf("deleteMin \n");
    printf("deleteMax \n");
    printf("count \n");
    printf("countRecursive \n");
    printf("printList \n");
    printf("exit \n");
    printf("---------------------------------------\n");
}

void processInsertFirst(){
    int num;
    scanf("%d",&num);
    insertFirst(num);
    printList();
}

void processInsertLast(){   
    int num;
    scanf("%d",&num);
    insertLast(num);
    printList();

}

void processRemoveAll(){
    int num;
    scanf("%d",&num);
    removeAllRecursive(&head , num);
    printList();

}

void processRemoveNode(){
    int num;
    scanf("%d",&num);
    removeNode(num);
    printList();

}

void processReverse(){
    reverse();
    printList();
}

void processDeleteMin(){
    deleteMin();
    printList();
}

void processDeleteMax(){
    deleteMax();
    printList();
}

void processCount(){
    printf("This list contains %d Node(s).\n",count());
}

void processCountRecursive(){
    printf("This list contains %d Node(s).\n",countRecursive(head));
}

//---------------------------------------------------------------------


int main(){
    processCommand();

    while (1) {
        char cmd[30];
        char c;
        scanf("%s",cmd);
        

        if (strcmp(cmd, "exit") == 0) break;
        else if (strcmp(cmd, "command") == 0) processCommand();
        else if (strcmp(cmd, "insertFirst") == 0) processInsertFirst();
        else if (strcmp(cmd, "insertLast") == 0) processInsertLast();
        else if (strcmp(cmd, "removeNode") == 0) processRemoveNode();
        else if (strcmp(cmd, "removeAll") == 0) processRemoveAll();
        else if (strcmp(cmd, "reverse") == 0) processReverse();
        else if (strcmp(cmd, "deleteMin") == 0) processDeleteMin();
        else if (strcmp(cmd, "deleteMax") == 0) processDeleteMax();
        else if (strcmp(cmd, "count") == 0) processCount();
        else if (strcmp(cmd, "printList") == 0) printList();
}
    
    freeList();
    return 0;    
}   

/*
command
insertFirst
insertLast
insertLastRecursive
removeNode
removeNodeRecursive
removeAllRecursive
reverse
printList
exit*/