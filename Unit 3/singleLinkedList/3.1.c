#include <stdio.h>

typedef struct Node{
    int value;
    Node* next;
} Node;

Node* push(Node* head,int v){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->value = v;
    newNode -> next = head;
    return newNode;
}

void printList(Node* head){
    Node* current = head;
    while ( current != NULL){
        printf("%d -> ",current -> value);
        current = current ->next;
    }
    printf("NULL \n");
}

void freeList(Node* head){
    Node* current = head;
    while (current != NULL){
        Node* next = current->next;
        free(current);
        current = next;
    }
}


int main(){
    Node * head = NULL;

    int n , data;
    printf("enter the number of elements you want to add to the list: ");
    scanf("%d",&n);

    for (int i = 0; i< n; i++){
        printf("enter the value for the element %d: ",i+1);
        scanf("%d",&data);
        head = push(head, data);
    }

    printf("your list: \n");
    printList(head);

    freelist(head);

    return 0;
}