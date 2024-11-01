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

Node* head = NULL, *tail = NULL;

Node* listNode[MAX*MAX]; 
int szList = 0;
int A[MAX][MAX];
int n,m;
int r0,c0;
int visited[MAX][MAX];

const int dr[4] = { 1 , -1 , 0 , 0};
const int dc[4] = { 0 , 0 , 1 , -1};

Node* finalNode;


Node* makeNode(int row, int col , int step , Node* parent){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->col = col;
    newNode->row = row;
    newNode->step = step;
    newNode->parent = parent;
    newNode->next = NULL;
    return newNode;
}

int queueEmpty(){
    return (head == NULL && tail == NULL);
}

void pushQueue(Node* tmp){
    if (queueEmpty()) {
        head = tmp;
        tail = tmp;
    }
    else {
        tail->next = tmp;
        tail = tmp;
    }
}

Node* popQueue(){
    if (queueEmpty()) return NULL;
    Node* tmp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    return tmp;
}

//------------------------------------------------------------------

void input(){
    FILE * fp = fopen("maze.txt" , "r");
    fscanf(fp, "%d%d%d%d",&n,&m,&r0,&c0);
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            fscanf(fp, "%d",&A[i][j]);
        }
    }

    fclose(fp);
}

int legal(int row, int col){
    return A[row][col] == 0 && !visited[row][col] ; 
}

int target(int row, int col){
    return (row < 1 || row > n || col <1 || col > m);
}

void finalize(){
    for(int i = 0; i < szList; i ++){
        free(listNode[i]);
    }
}

void addList(Node* node){
    listNode[szList] = node;
    szList++;
}



//------------------------------------------------------------------

int main(){
    printf("MAZE\n");
    input();
    for (int r= 1; r <= n; r ++){
        for(int c = 1; c <= m; c++){
            visited[r][c] = 0;
        }
    }

    Node* startNode = makeNode(r0,c0, 0 , NULL);
    addList(startNode);
    pushQueue(startNode);
    visited[r0][c0] = 1;
    while (!queueEmpty()){
        Node* node = popQueue();
        printf("POP (%d,%d)\n", node->row , node->col);
        for (int k = 0; k < 4; k ++){
            int nr = node->row + dr[k];
            int nc = node->col + dc[k];
            if (legal(nr,nc)){
                visited[nr][nc] = 1;
                Node* newNode = makeNode(nr , nc , node->step+1 , node);
                addList(newNode);
                if (target(nr,nc)){
                    finalNode = newNode ; 
                    break;
                }
                else {
                    pushQueue(newNode);
                }
            }
        }
        if (finalNode != NULL) break;
    }
    Node* s = finalNode;
    int step = finalNode->step;
    while (s != NULL){
        printf(" (%d,%d) ", s->row , s->col);
        s = s->parent;
    }
    printf("\n");
    printf("Step : %d",step);
    finalize();
    return 0;
}