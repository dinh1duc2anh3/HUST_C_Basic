#include <stdio.h>
#include <stdlib.h>


//--------------------------------------------------------------------


#define N 1000

int n;
int a[N];

//--------------------------------------------------------------------


typedef struct Node{
    int key;
    struct Node* leftChild;
    struct Node* rightChild;

} Node;

Node* root = NULL;

Node* makeNode(int v){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = v;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Node* insert(Node* r , int v){
    if (r == NULL) {
        r = makeNode(v);
    }
    else if (r->key > v){
        r->leftChild = insert(r->leftChild , v);
    }
    else if (r->key < v){
        r->rightChild = insert(r->rightChild , v);
    }
    return r;

}

Node* search(Node* r , int v){
    if ( r == NULL) return NULL;
    if (r->key == v) return r;
    if  (r->key > v) return search(r->leftChild , v);
    return search(r->rightChild , v);
}

Node* minNode = NULL;
Node* findMin(Node* r) {
    if (r == NULL)
        return NULL;
    Node* nodeMin = findMin(r->leftChild);
    if (nodeMin != NULL ) return nodeMin;
    return r;
}

Node* del(Node* r , int v){
    if (r == NULL) return NULL;
    if (r->key < v) r->rightChild =  del(r->rightChild , v);
    else if (r->key > v) r-> leftChild =  del(r->leftChild , v);
    else {
        if (r->leftChild != NULL && r->rightChild != NULL) {
            Node* tmp = findMin(r->rightChild );
            r->key = tmp->key;
            r->rightChild = del(r->rightChild , tmp->key);
        }
        else {
            Node* tmp = r;
            if ( r-> leftChild == NULL) r= r->rightChild;
            else r = r->leftChild;
            free(tmp);
        }
    }
        return r;

}

//--------------------------------------------------------------------



void swap(int* a, int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void input(FILE * fp){
    fscanf(fp,"%d",&n);
    for (int i = 1; i <= n ; i++){
        fscanf(fp,"%d",&a[i]);
    }
}

void processInput(){
    char * filename = "data.txt";
    FILE* fp = fopen(filename , "r");
    input(fp);
    fclose(fp);
    printf("Load successfully %s.\n",filename);
}

void printArray(int a[] , int n){
    
        for (int i = 1; i <= n; i ++){
            printf("%d ",a[i]);
        }
        printf("\n");
    
    
}



//--------------------------------------------------------------------
int main(){
    processInput();
    printArray(a , n);

    for (int i = 1;  i <= n; i ++){
        insert(root , a[i]);
    }

    Node* minNode = findMin(root);
    printf("Min node = %d\n",minNode->key);

    return 0;
}