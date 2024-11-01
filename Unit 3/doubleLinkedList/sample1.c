/*double Linked List using  head , last , 
function that use Global Variables : head , last*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//---------------------------------------------------------------------


typedef struct Node{
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

Node * head = NULL;
Node * last = NULL;

Node* makeNode(int v){
    Node*  p = (Node*)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

Node* insertFirst(int v){
    Node* newNode= makeNode (v);
    if (head == NULL){
        head = newNode;
        last = newNode;
        return head;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

Node* insertLast(int v){
    Node* newNode= makeNode (v);
    if (head == NULL){
        head = newNode;
        last = newNode;
        return head;
    }
    last->next = newNode;
    newNode->prev = last;
    last = newNode;
    return head;
}

Node* removeNode(int v){
    if (head == NULL)return NULL;
    if (head->value == v){
        Node* tmp = head;
        head = head->next;
        head->prev = NULL;
        free(tmp);
        return head;
    }

    Node* p =head;
    while (p != NULL){
        if (p->value == v){

            if (p == last){
                p->prev->next = NULL;
                last =p->prev;
                free(p);
                return head;
            }


            p->next->prev = p->prev;
            p->prev->next = p->next;
            free(p);
            return head;
        }
        p = p->next;
    }
    return head;

}

Node* removeAllRecursive(Node** head , int v){
    if (* head== NULL) return NULL;
    if ((*head)->value == v){
        Node* tmp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(tmp);
        
        *head = removeAllRecursive(head , v);
    }

    (*head) ->next = removeAllRecursive(&((*head)->next) , v);
    return *head;

}

Node* deleteMin(){
    if (head == NULL) return NULL;

    Node* minNode = head;
    Node* p = head;
    while ( p != NULL){
        if (p->value < minNode->value){
            minNode = p;
        }
        else p = p->next;
    }


    removeNode(minNode->value);
    return head;
}

Node* deleteMax(){
    if (head == NULL) return NULL;

    Node* maxNode = head;
    Node* p = head;
    while ( p!= NULL){
        if (p->value > maxNode->value){
            maxNode = p;
        }
        else p = p->next;
    }

    removeNode(maxNode->value);
    return head;
}

int countRecursive(Node* head){
    if (head == NULL) return 0;
    return 1 + countRecursive(head->next);
}

void printListLeft2Right(){
    printf("List (left to right) : ");
    Node* p = head;
    while (p != NULL){
        printf("%d ",p->value);
        p = p->next;
    }
    printf("\n");
}   

void printListRight2Left(){
    printf("List (right to left) : ");
    Node* p = last;
    while (p != NULL){
        printf("%d ",p->value);
        p = p->prev;
    }
    printf("\n");
}

void freeList(){
    Node* p = head;
    Node* np = NULL;
    while (p != NULL){
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
    printf("deleteMin \n");
    printf("deleteMax \n");
    printf("count \n");
    printf("printL2R \n");
    printf("printR2L \n");
    printf("exit \n");
    printf("---------------------------------------\n");
}

void processInsertFirst(){
    int num;
    scanf("%d",&num);
    insertFirst(num);
    printListLeft2Right();
}

void processInsertLast(){   
    int num;
    scanf("%d",&num);
    insertLast(num);
    printListLeft2Right();

}

void processRemoveAll(){
    int num;
    scanf("%d",&num);
    removeAllRecursive(&head , num);
    printListLeft2Right();

}

void processRemoveNode(){
    int num;
    scanf("%d",&num);
    removeNode(num);
    printListLeft2Right();

}

void processDeleteMin(){
    deleteMin();
    printListLeft2Right();
}

void processDeleteMax(){
    deleteMax();
    printListLeft2Right();
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
        else if (strcmp(cmd, "remove") == 0) processRemoveNode();
        else if (strcmp(cmd, "removeAll") == 0) processRemoveAll();
        else if (strcmp(cmd, "deleteMin") == 0) processDeleteMin();
        else if (strcmp(cmd, "deleteMax") == 0) processDeleteMax();
        else if (strcmp(cmd, "count") == 0) processCountRecursive();
        else if (strcmp(cmd, "printL2R") == 0) printListLeft2Right();
        else if (strcmp(cmd, "printR2L") == 0) printListRight2Left();
}
    
    freeList();
    return 0;    
}   
