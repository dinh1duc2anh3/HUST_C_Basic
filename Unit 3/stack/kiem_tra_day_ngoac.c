/*stack*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct Node{
    char c;
    struct Node* next;
} Node;

Node * top;

Node* makeNode(char x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->c = x;
    newNode-> next = NULL;
    return newNode;
}

void initStack(){
    top = NULL;
}

int stackEmpty(){
    if (top == NULL) return 1;
    return 0;
}

void push(char x){
    Node* p =makeNode(x);
    p->next = top;
    top = p;
}

char pop(){
    if (stackEmpty()) return ' ';
    char x = top->c;
    Node* tmp = top;
    top = top->next;
    free (tmp);
    return x;
}

int match(char x,char y){
    if (x == '{' && y == '}') return 1;
    if (x == '[' && y == ']') return 1;
    if (x == '(' && y == ')') return 1;
    return 0;

}

int check(char * s){
    initStack();
    for (int i = 0; i < strlen(s); i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') push(s[i]);
        else {
            if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
                 if (stackEmpty()) return 0;
                char x = pop();
                if (!match(x,s[i])) return 0;
            }
           
        }
    }
    if (stackEmpty()) return 1;
    else return 0;
}

int main(){
    char str[MAX_LEN];
    printf("nhap xau ngoac(max = 100): ");
    scanf("%s",str);
   if ( check(str)) printf("xau %s hop le.\n");
   else printf("xau %s khong hop le.\n");
    



    return 0;
}