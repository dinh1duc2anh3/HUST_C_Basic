#include <stdio.h>
#include <string.h>

#define MAX_LEN 30

typedef struct Node{
    int num;
    char* line;
    struct Node* next;
}Node;

Node* head;



void initList(){
    head = NULL;
}

Node* makeNode(int x, char* y){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->num = x;
    strcat(newNode->line,y);
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head){
    Node * p = head;
    printf("Bus Line List\n");
    while (p!=NULL){
        printf("%d\n%s\n%p\n",p->num,p->line,p);
        p = p->next;
    }
}

void addLineToFirst(int x,char* y){
    Node* p = makeNode(x,y);
    p->next = head;
    head = p;
}

void addLineToLast(int x,char* y){
    Node* newNode = makeNode(x,y);
    Node* p = head;//a b c
    while ( p->next != NULL) {
        p = p-> next;
    }
    p->next = newNode;

}

void search(int x){
    Node* p = head;
    int cnt = 0;
    while (p != NULL){
        if (p->num == x) {
            printf("Bus line %d named: %s.\n",p->num,p->line);
            cnt++;
            break;
            
        }
        p = p-> next;
    }
    if (cnt == 0) printf("No bus line available!.\n");
    
}

void delete(int x){
    Node* p = head;
    int cnt = 0; // a b c
    if (head->num == x){
        Node*tmp = head;
        head = head->next;
        free(head);
        cnt++;
    }
    else {
        while (p != NULL){
        if (p->next->num == x){
            if (p->next->next == NULL){
                Node* tmp = p->next;
                p->next = NULL;
                free(tmp);
                cnt++;
                break;
            }
            Node* tmp = p->next;
            p->next = tmp->next;
            free(tmp);

            cnt++;
            break;
        }
        p = p-> next;
    }
    }
    
    if (cnt == 0) printf("No bus line available!.\n");
}

int numberOfBusLine(Node* head){
    Node* p = head;
    int cnt = 0;

    while (p != NULL){
        cnt++;
        p= p->next;
    }
    return cnt;
}

void sorting(Node* head){
    //a1 b3 c2 d4 e6
}

void input(){
    char filename = "busline.txt";
    FILE * f = fopen(filename,"r");
    int x;
    char* y;
    while (fscanf(f,"%d\n%30s",&x,y) != EOF){
        
        addLineToLast(x,y);
    }
    fclose(f)
}

void output(){
    char filename = "busline.txt";
    f = fopen(filename,"w");
    Node* p = head;
    while (p!= NULL) {
        fprintf("%d\n%30s\n");
        p= p->next;
    }
    fclose(f);
}


    




int main(){
    while(1){
        if ()
    }
    return 0;
}