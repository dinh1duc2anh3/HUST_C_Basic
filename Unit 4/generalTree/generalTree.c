/*general tree */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------

typedef struct Node{
    char name[256];
    struct Node* leftMostChild;
    struct Node* rightSibling;
} Node;

Node* root;


Node* makeNode(char* name){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name , name);
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;
    return newNode;
}

Node* find(Node* r , char * name){
    if (r == NULL) return NULL;
    if (strcmp(r->name , name) == 0) return r;
    Node* p = r->leftMostChild;
    while (p != NULL){
        Node* q = find(p , name);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
}

Node* addLast(Node* p , char* name){
    if (p == NULL ) return makeNode(name);
    p->rightSibling = addLast(p->rightSibling , name);
    return p;
}

void addChild(char* name , char* child){
    Node * r = find(root , name);
    if (r == NULL) return ;
    r->leftMostChild = addLast(r->leftMostChild , child);
}


void printTree(Node* r){
    if (r == NULL) return ;
    if (r->leftMostChild == NULL) return;
    printf("%s: ",r->name);
    Node* p = r->leftMostChild;
    while (p != NULL){
        printf("%s ",p->name);
        p = p->rightSibling;
    }
    printf("\n");
    p = r->leftMostChild;
    while( p != NULL){
        printTree(p);
        p = p->rightSibling;
    }

}

void printTreeF (Node* r , FILE * fp){
    if (r== NULL) return;
    if (r->leftMostChild == NULL) return;
    fprintf(fp ,"%s: ",r->name);
    Node* p = r->leftMostChild;
    while (p != NULL){
        fprintf(fp,"%s ",p->name);
        p = p->rightSibling;
    }
    fprintf(fp,"$\n");
    p  = r->leftMostChild;
    while (p != NULL){
        printTreeF(p, fp);
        p = p->rightSibling;
    }
}

int height(Node* p){
    //problem 1
    if (p == NULL ) return 0;
    int maxH = 0;
    Node* q = p->leftMostChild;
    while (q != NULL){
        int h = height(q);
        if (maxH < h) maxH = h;
        q = q->rightSibling;
    }
    return 1+ maxH;
}

int count(Node* r){
    if (r == NULL) return 0;
    int cnt = 1;
    Node* p = r->leftMostChild;
    while (p != NULL){
        cnt += count(p);
        p = p->rightSibling;
    }
    return cnt;
}

void freeTree(Node* r){
    if (r == NULL) return ;
    Node* p = r->leftMostChild;
    while (p != NULL){
        Node* sp = p->rightSibling;
        freeTree(p);
        p = sp;
    }
    printf("free node %s\n",r->name);
    free(r);
    //problem2
    r = NULL;

}

Node* load(char* filename){
    FILE* fp = fopen(filename , "r");
    if (fp == NULL) {
        printf("cannot open %s",filename);
        return NULL;
    }
    root = NULL;
    Node* currentNode = NULL;
    char name[256];

    while ( fscanf(fp, "%s",name) == 1){
        if (root == NULL) {
            root = makeNode(name);
            currentNode = root;
        }
        else if (strcmp(name , "$$") == 0){
            break;
        }
        else if (strcmp(name , "$" ) == 0){
            currentNode = NULL;
        }

        else {
            if (currentNode == NULL){
                currentNode = find(root , name);
            }
            else addChild(currentNode->name, name);
        }
        
    }

    fclose(fp);
    printf("Loaded %s successfully.\n",filename);
    return root;
}

//------------------------------------------------------------------


void processCommand(){
    printf("-------------List of Commands-------------\n");
    printf("command \n");
    printf("load\n");
    printf("print\n");
    printf("find\n");
    printf("findChilren \n");
    printf("height \n");
    printf("count \n");
    printf("addChild \n");
    printf("store\n");
    printf("exit \n");
    printf("---------------------------------------\n");
}



void processLoad(){
    char* filename = "generalTree.txt";
    root = load(filename);
}

void processFind(){
    char name[256];
    scanf("%s",name);
    Node* p = find(root , name);
    if (p == NULL) printf("Not Found %s\n",name);
    else printf("Found %s\n",name);
}

void processFindChildren(){
    char name[256];
    scanf("%s",name);
    Node* p = find(root , name);
    if (p == NULL) printf("Not Found %s\n",name);
    else {
        printf("Found %s with children: ",name);
        Node* q = p->leftMostChild;
        while (q != NULL){
            printf("%s ",q->name);
            q= q->rightSibling;
        }
    }
    printf("\n");
}

void processHeight(){
    char name[256];
    scanf("%s",name);
    Node* p = find(root , name);
    if (p == NULL) printf("Not Found %s\n",name);
    else {
        printf("Found %s having height = %d\n",name,height(p));
    }
}


void processCount(){
    printf("Number of members is %d\n",count(root));
}


void processStore(){
    char filename[256] = "generalTreeDes.txt";
    FILE* fp = fopen(filename , "w");
    printTreeF(root , fp);
    fprintf(fp,"$$");
    fclose(fp);
    printf("Stored successfully general tree in %s.\n",filename);
}

void processAddChild(){
    char name[256];
    char child[256];
    scanf("%s %s",name,child);
    Node* p = find(root , name);
    if (p == NULL) printf("Not Found %s\n",name);
    else {
        addChild(name , child);
        printf("Added %s as last child of %s\n",child , name);
    }
}


//------------------------------------------------------------------


int main(){
    processCommand();
    while (1){
        char cmd[256];
        scanf("%s",cmd);
        if (strcmp(cmd, "exit") == 0) break;
        else if ( strcmp(cmd, "load") == 0) processLoad();
        else if ( strcmp(cmd, "command") == 0) processCommand();
        else if ( strcmp(cmd, "print") == 0) printTree(root);
        else if ( strcmp(cmd, "find") == 0) processFind();
        else if ( strcmp(cmd, "findChildren") == 0) processFindChildren();
        else if ( strcmp(cmd, "height") == 0) processHeight();
        else if ( strcmp(cmd, "count") == 0) processCount();
        else if ( strcmp(cmd, "addChild") == 0) processAddChild();
        else if ( strcmp(cmd, "store") == 0) processStore();
    }

    freeTree(root);
    return 0;
}

/*
load
print
find
findChildren
height
count
addChild
store*/

/*
david jame peter john $
jame mike $
peter mary daisy $
$$
*/