#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//-------------------------------------------------------------------

typedef struct Node{
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* root;


Node* makeNode(int id){
    Node* newNode = (Node* )malloc (sizeof(Node));
    newNode->id = id;
    newNode -> leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Node* find(Node* r , int id){
    if (r == NULL) return NULL;
    if (r->id == id) return r;
    Node* findLeft = find(r->leftChild , id);
    if (findLeft != NULL) return findLeft;
    return find(r->rightChild , id);

}

void printTree(Node* r){

    if (r ==NULL) return ;
    if (r->leftChild == NULL && r-> rightChild == NULL ) return ;
    printf("%d: ",r->id);
    if (r->leftChild == NULL) printf("left = NULL");
    else printf("left = %d",r->leftChild->id);
    if (r->rightChild == NULL) printf(", right = NULL");
    else printf(", right = %d",r->rightChild->id);
    printf("\n");
    //problem1
    printTree(r->leftChild);
    printTree(r->rightChild);


}

void printTreeF(Node * r, FILE * fp){
    if (r == NULL) return ;
    if (r->leftChild == NULL && r-> rightChild == NULL ) return ;
    fprintf(fp,"%d ",r->id);
    if (r->leftChild == NULL) fprintf(fp,"-1 ");
    else fprintf(fp,"%d ",r->leftChild->id);
    if (r->rightChild == NULL) fprintf(fp,"-1 " );
    else fprintf(fp,"%d ",r->rightChild->id);
    fprintf(fp,"\n");

    printTreeF(r->leftChild,fp);
    printTreeF(r->rightChild,fp);

}

void addLeftChild(int u, int id){
    Node* pu  = find(root , u);
    if (pu == NULL) {
        printf("Node %d not exists.\n",u );
        return ;
    }
    if (pu -> leftChild != NULL) {
        printf("Node %d already has left child.\n",u);
        return;
    }

    if ( find(root, id) != NULL) {
        printf("Node %d already exists.\n",id);
        return ;
    }

    

    pu->leftChild = makeNode(id);
    printf("Successfully added %d to the left of %d.\n",id,u);

}

void addRightChild(int u , int id){
    Node* pu  = find(root , u);
    if (pu == NULL) {
        printf("Node %d not exists.\n",u );
        return ;
    }
    if (pu -> rightChild != NULL) {
        printf("Node %d already has right child.\n",u);
        return;
    }

    if ( find(root, id) != NULL) {
        printf("Node %d already exists.\n",id);
        return ;
    }

    

    pu->rightChild = makeNode(id);
    printf("Successfully added %d to the right of %d.\n",id,u);
}

int count(Node* r){
    if (r == NULL) return  0;
    return 1 + count (r->leftChild) + count(r->rightChild);
}

int height(Node * p){
    if (p == NULL) return 0;
    int leftHeight = height(p->leftChild);
    int rightHeight = height(p->rightChild);
    int maxH = (leftHeight > rightHeight ? leftHeight : rightHeight) ;
    return 1 + maxH;
}

void printLeaves(Node* r){
    if ( r== NULL) return ;
    if (r->leftChild == NULL && r->rightChild == NULL) printf("%d ",r->id);
    printLeaves(r->leftChild);
    printLeaves(r->rightChild);
}

void load(char * filename){
    FILE * fp = fopen (filename , "r");
    root = NULL;
    Node* currentNode = NULL;
    int p , a,  b;

    while (fscanf(fp,"%d",&p) == 1){     
        if (p == -2) break;

        if (root == NULL){
            root = makeNode(p);
            currentNode = root;
        }
        else {
            currentNode = find(root , p);
        }
        fscanf(fp,"%d %d",&a,&b);
        if ( a != -1 ) currentNode->leftChild = makeNode(a);

        if (b != -1)  currentNode->rightChild = makeNode(b);
    }


    fclose(fp);
    printf("Load successfully %s.\n",filename);
}

void freeTree(Node* r){
    if (r == NULL) return ;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

//-------------------------------------------------------------------


void processCommand(){
    printf("-------------List of Commands-------------\n");
    printf("command \n");
    printf("load\n");
    printf("print\n");
    printf("find\n");
    printf("addLeft \n");
    printf("addRight \n");
    printf("height \n");
    printf("count \n");
    printf("printLeaves \n");
    printf("store\n");
    printf("exit \n");
    printf("---------------------------------------\n");
}


void processLoad(){
    char* filename =  "binaryTree.txt";
    load(filename);
}

void printChildren(Node* p){
    if( p->leftChild == NULL) printf("no leftChild");
    else printf("leftChild = %d",p->leftChild->id);
    if (p->rightChild == NULL) printf(", no rightChild.\n");
    else printf(", RightChild = %d\n",p->rightChild->id);
}

void processFind(){
    int id;
    scanf("%d",&id);
    Node* p = find(root , id);
    if (p == NULL){
        printf("Cannot find Node %d.\n",id);
        return;
    }
    else {
        printf("Found Node %d: \n",id);
        printChildren(p);

    }
}

void processStore(){
    char * filename = "binaryTreeDes.txt";
    FILE* fp = fopen (filename , "w");

    printTreeF(root , fp);
    fprintf(fp,"-2");
    fclose(fp);
    printf("Stored successfully in %s.\n",filename);
}

void processAddLeftChild(){
    int u,id;
    scanf("%d %d",&u,&id);
    addLeftChild(u,id);
}

void processAddRightChild(){
    int u,id;
    scanf("%d %d",&u,&id);
    addRightChild(u,id);
}

void processCount(){
    printf("Tree has %d nodes.\n",count(root));
}

void processHeight(){
    int id;
    scanf("%d",&id);
    Node* p = find (root , id);
    if (p == NULL) {
        printf("Cannot find Node %d.\n",id);
        return ;
    }

    printf("The height of %d is %d.\n",id,height(p));
}

void processPrintLeaves(){
    printLeaves(root);
    printf("\n");
}


//-------------------------------------------------------------------

int main(){
    processCommand();
    while (1){
        char cmd[256];
        scanf("%s",cmd);
        if (strcmp(cmd, "exit") == 0) break;
        else if ( strcmp(cmd, "load") == 0) processLoad();
        else if ( strcmp(cmd, "print") == 0) printTree(root);
        else if ( strcmp(cmd, "command") == 0) processCommand();
        else if ( strcmp(cmd, "addLeft") == 0) processAddLeftChild(root);
        else if ( strcmp(cmd, "addRight") == 0) processAddRightChild(root);
        else if ( strcmp(cmd, "find") == 0) processFind();
        else if ( strcmp(cmd, "height") == 0) processHeight();
        else if ( strcmp(cmd, "count") == 0) processCount();
        else if ( strcmp(cmd, "printLeaves") == 0) processPrintLeaves();
        else if ( strcmp(cmd, "store") == 0) processStore();
    }

    freeTree(root);
    return 0;
}

