#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* root;


Node* makeNode(int key){
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->key = key;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}




Node* find(Node* r,int key){
    if (r == NULL) return NULL;
    if (r->key == key) return r;
    Node* p = find(r->leftChild,key);
    if (p!= NULL) return p;
    return find(r->rightChild,key);
}

void processFind(){
    int key;
    scanf("%d",&key);
    Node* p = find(root,key);
    if (p == NULL) printf("Unable to find %d in the tree\n",key);
    else {
        printf("Found %d in the tree\n",key);
    }
    return;
}

void addLeftChild(Node* r,int current_key,int key){
    Node* p = find(r,current_key);
    if (p == NULL) return;  
    Node* valid = find(r,key);
    if (valid == NULL) {
        Node* child = makeNode(key);
        p->leftChild = child;
    }
} 

void processAddLeftChild(){
    int current_key,key;
    printf("Enter current key: ");
    scanf("%d",&current_key);
    printf("Enter left child's key: ");
    scanf("%d",&key);
    if (find(root,current_key) == NULL) printf("Current node non-existed\n");
    if (find(root,key) != NULL) printf("Child's key existed\n");
    else {
        addLeftChild(root,current_key,key);
    }
    return;
}

void addRightChild(Node* r,int current_key,int key){
    Node* p = find(r,current_key);
    if (p == NULL) return;  
    Node* valid = find(r,key);
    if (valid == NULL) {
        Node* child = makeNode(key);
        p->rightChild = child;
    }
}

void processAddRightChild(){
    int current_key,key;
    printf("Enter current key: ");
    scanf("%d",&current_key);
    printf("Enter right child's key: ");
    scanf("%d",&key);
    if (find(root,current_key) == NULL) printf("Current node non-existed\n");
    if (find(root,key) != NULL) printf("Child's key existed\n");
    else {
        addRightChild(root,current_key,key);
    }
    return;
}

void Load (char* filename){
    FILE* f = fopen(filename,"r");
    root = NULL;
    while (1){
        int u;
        fscanf(f,"%d",&u);
        if (u == -2) break;
        if (root == NULL) root = makeNode(u);
        int l,r;
        fscanf(f,"%d%d",&l,&r);
        if (l> -1) addLeftChild(root,u,l);
        if (r > -1) addRightChild(root,u,r);
        printf("%d %d %d\n",u,l,r);
    }

    fclose(f);
}

void processLoad(){
    char filename[256]="binarytree.txt";
    Load(filename);
}

int Count(Node* r){
    if (r == NULL) return 0;
    return 1+Count(r->leftChild) + Count(r->rightChild);
}

void processCount(){
    printf("Number of nodes if the tree : %d\n",Count(root));
}



int Leaves(Node* p){
    if (p->leftChild == NULL && p->rightChild == NULL) return 1;
    return 0;
}

void findLeaves(Node* r){
    if (r == NULL) return ;
    if (Leaves(r)) printf("%d ",r->key);
    findLeaves(r->leftChild);
    findLeaves(r->rightChild);   
}

void processFindLeaves(){
    printf("Leaves: ");
    findLeaves(root);
    printf("\n");
}

int height(Node* p){
    int maxH = 0;
    int hl = height(p->leftChild);
    if (maxH < hl) maxH = hl;
    int hr = height(p->rightChild);
    if (maxH < hr) maxH = hr;
    return maxH+1;
}

void processHeight(){
    int key;
    scanf("%d",&key);
    Node* p = find(root,key);
    if (p == NULL) printf("Not found %d\n",key);
    else printf("Height of %d is %d\n",key,height(p));
}


void print(Node* r){
    if ( r== NULL) return;
    printf("%d : ",r->key);
    if (r->leftChild == NULL) printf("no left child\n");
    else printf("left child is %d\n",r->leftChild->key);

    if (r->rightChild == NULL) printf("no right child\n");
    else printf("right child is %d\n",r->rightChild->key);

    print(r->leftChild);
    print(r->rightChild);
}

void processOptions(){
    printf("---------Options------\nLoad\nPrint\nAddLeftChild\nAddRightChild\nFind\nCount\nFindLeaves\nHeight\nStore\n");
}

void freeTree(Node* r){
    if (r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
    r = NULL;
}
int main(){
    processOptions();
    while (1){
        char cmd[256];
        printf("Enter a command: ");
        scanf("%s",cmd);
        if (strcmp(cmd,"Quit") == 0) break;
        else if (strcmp(cmd,"Options" )== 0) processOptions();
        else if (strcmp(cmd,"Load") == 0) processLoad();
        else if (strcmp(cmd,"Print") == 0) print(root);
        else if (strcmp(cmd,"AddLeftChild") == 0) processAddLeftChild;
        else if (strcmp(cmd,"AddRightChild") == 0) processAddRightChild;
        else if (strcmp(cmd,"Find") == 0) processFind;
        else if (strcmp(cmd,"Count") == 0) processCount();
        else if (strcmp(cmd,"FindLeaves") == 0) processFindLeaves();
        else if (strcmp(cmd,"Height") == 0) processHeight();
        // else if (strcmp(cmd,"Store") == 0) processStore();
    }
    freeTree(root);
    return 0;
}