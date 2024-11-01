#include <stdio.h>
#include <stdlib.h>

#define MAX 100


//------------------------------------------------------------------

typedef struct Node{
    int row , col;
    int step;
    struct Node* next;
    struct Node* parent;
} Node;

int A[MAX][MAX];
int visited[MAX][MAX];
Node* listNode[MAX*MAX];
int szList ;
int n, m , r0 , c0;
Node* finalNode = NULL;

int dc[4] = {0 , 0 , 1 , -1};
int dr[4] = { 1 , -1 , 0 , 0};


//------------------------------------------------------------------



Node* head = NULL , * tail = NULL;

int queueEmpty(){
    return head == NULL && tail == NULL;
}

Node* makeNode(int row , int col , int step , Node* parent){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->col = col;
    newNode->row = row;
    newNode->step = step;
    newNode->parent = parent;
    newNode->next = NULL;
    return newNode;
}

void pushQueue(Node* newNode){
    if (queueEmpty()){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

Node* popQueue(){
    if (queueEmpty()) return NULL;
    Node* tmp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    return tmp;
}

int target(int row , int col){
    return (row< 1 || row > n || col < 1 || col >m );
}

int valid(int row , int col){
    return !visited[row][col] && A[row][col] == 0;
}


void addList(Node* node){
    listNode[szList] = node;
    szList++;
}

void freeList(){
    for (int i = 0; i < szList ; i ++){
        free(listNode[i]);
    }
}

//------------------------------------------------------------------

void input(){
    FILE* fp = fopen("maze.txt" , "r");
    fscanf(fp,"%d %d %d %d", &n, &m , &r0, &c0  );
    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= m ; j ++){
            fscanf(fp,"%d",&A[i][j]);
        }
    }
    fclose(fp);
}

void initVisit(){
    //problem1 : den max hay den n , m
    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= m ; j ++){
            visited[i][j] = 0;
        }
    }
}




//------------------------------------------------------------------
int main (){
    printf("MAZE\n");
    input();
    initVisit();

    Node* startNode = makeNode (r0 , c0 , 0 , NULL);
    addList(startNode);
    pushQueue(startNode);
    visited[r0][c0] = 1;

    while (!queueEmpty()){
        Node* popNode = popQueue();
        printf("POP (%d,%d)\n",popNode->row , popNode->col);
        for (int k = 0; k < 4 ; k ++){
            int nr = popNode->row + dr[k];
            int nc = popNode->col + dc[k];

            if (valid(nr , nc)){
                visited[nr][nc] = 1;
                Node* relatedNode = makeNode(nr, nc , popNode->step + 1 , popNode);
                addList(relatedNode);
                if (target(nr , nc)){
                    finalNode = relatedNode;
                    break;
                }
                else {
                    pushQueue(relatedNode);

                }
            }
        }
        if (finalNode != NULL) break;
    }
    Node* s = finalNode;
    int step = s->step;
    while (s != NULL){
        printf("(%d,%d) ",s->row , s->col);
        s = s->parent;
    }
    printf("\nStep: %d",step);

    freeList();

    return 0;
}