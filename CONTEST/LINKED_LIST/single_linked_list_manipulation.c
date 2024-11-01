#include <stdio.h>

#define N 1000

typedef struct Node{
    int num;
    struct Node * next;
} Node;

Node* head;

Node* makeNode(int num){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}
//problem neu v chua ton tai?
Node* addFirst(Node* head,int v){
    Node* p = makeNode(v);
    if (head == NULL) return p;
    p->next = head;
    head = p;
    return p;
}


Node* addLast(Node* head,int v){
    Node* p = makeNode(v);
    if (head == NULL) return p;
    Node* q = head;
    while (q->next != NULL){
        q=q->next;
    }
    q->next = p;
    return head;
}

Node* addAfter(Node* head, int u, int v){
    Node* newNode = makeNode(u);
    Node* p = head;
    while (p->next != NULL){
        if (p->num == v) 
    }
}

int main(){
    int n;
    int a[N]; //luu cac so nguyen duong a1 a2 a3 ... an
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d ",&a[i]);
    }
    //problem: nhap lenh vao?
    while(1){
        
    }

    return 0;
}