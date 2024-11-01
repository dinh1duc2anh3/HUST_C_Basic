#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

typedef struct Node{
    char name[MAX_LEN];
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Node;

//Node dau la gi ?
Node* root;


//makeNode

Node* makeNode(char* name) {
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}


//Find(r,name)
Node* find(Node* r, char* name){
    if (r == NULL) return NULL;
    if (strcmp(r->name,name)==0) return r;
    Node* p = r->leftMostChild;
    while (p!= NULL) {
        Node* q = find(p,name);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
    //question: ham nay tra ve node co ten name dung khong? 
    // con neu nhu khogn tim thay thi tra ve null
}


//addLast(p,name)
//question: chua hieu code cho nay lam
Node* AddLast (Node* p,char* name) {
    Node* newNode = makeNode(name);
    if ( p == NULL ) return newNode;
    p->rightSibling = AddLast(p->rightSibling,name);
    return p;
//question: p la node dau cua day cac node con a? 
// question: ham addlast la them vao cuoi day con 1 node nua
}

//addChild(name,child)
void addChild(char* name,Node* child){
    Node* p = find(root,name);
    if (p == NULL) return ;
    Node* q = p->leftMostChild;
    AddLast(q,child) //question? tai sao trong ham addLast thi tham so la name 
    // ma o day tham so lai la mot node?
    
}



//printTree : in cay ra man hinh
void printTree(Node* r) {
    if ( r == NULL ) return ;
    printf("%s: ",r->name);
    Node* p = r ->leftMostChild;
    while (p != NULL) {
        printf("%s ",p->name);
        p = p->rightSibling;
    }
    
    p = r->leftMostChild;
    while( p != NULL) {
        printTree(p);
        p = p->rightSibling;
    }


}


//printTreef : in cay vao file 
void printTreeF (Node* r,FILE* f){
    if (r == NULL) return;
    fprintf(f,"%s: ",r->name);
    Node* p = r->leftMostChild;
    while (p != NULL){
        fprintf(f,"%s ",p->name);
        p= p->rightSibling;
    }

    p = r->leftMostChild;
    while ( p!= NULL){
        printTreeF(p);
        p = p->rightSibling;
    }
}


//processFind: ham xu li du lieu find
void processFind(){
    char name[MAX_LEN];
    scanf("%s",name);
    Node* p = find(root,name);
    if (p == NULL) printf("Not Found!\n");
    else printf("Found %s\n",name);
}


//processFindChildren : tim ham co ten la name, va in ra day con cua no
void processFindChildren(){
    char name[MAX_LEN];
    scanf("%s",name);
    Node* p = find(root,name);
    if ( p == NULL) printf("Not Found!\n");
    else {
        printf("Found %s with children: ",name);
        Node* q = p->leftMostChild;
        while ( p != NULL) {
            printf("%s ",q->name);
            q = q->rightSibling;
        }
    }
    printf("\n");
}



//height
int height (Node* p){
    
}


//count
//processStore
//freeTree




//error
void Load (char* filename) {
    fp = fopen(filename,"r");

    fclose(fp);
}

void FindChildren(char* a){

}

int main (){
    return 0;
}