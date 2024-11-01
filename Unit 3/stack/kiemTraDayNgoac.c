#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

//-------------------------------------------------------------------

typedef struct Node{
    char c;
    struct Node* next;
} Node;

Node* top = NULL;

int stackEmpty(){
    return (top == NULL) ;
}

Node* makeNode(char c){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->c = c;
    newNode->next = NULL;
    return newNode;
}

Node* push(char c){
    Node* newNode = makeNode(c);
    if (stackEmpty()){
        top = newNode;
        return top;
    }
    newNode->next = top;
    top = newNode;
    return top;
}

char pop(){
    if (!stackEmpty()){
        char x = top->c;
        Node* tmp = top;
        top = top->next;
        free(tmp);
        return x;
    }
    else return ' ';
}

int match(char x, char y){
    if (x == '{' && y == '}') return 1;
    if (x == '[' && y == ']') return 1;
    if (x == '(' && y == ')') return 1;
    return 0;
}

int check(char* s){
    for (int i = 0; i < strlen(s) ; i ++){
        if (s[i] == '{' || s[i] == '[' || s[i] == '('){
            push(s[i]);
        }
        else {
            if (s[i] == ']' || s[i] == '}' || s[i] == ')' ) {
                
                if (stackEmpty()) return 0;
                char c = pop();
                if (!match(c , s[i]) ) return 0;
            }
        }
        
    } 
    return (stackEmpty());
}

//-------------------------------------------------------------------


int main(){
    char str[MAX_LEN];
    printf("nhap xau ngoac(max = 100): ");
    scanf("%s",str);
    if (check(str)) printf("xau %s hop le.\n",str);
    else printf("xau %s khong hop le.\n",str);
    return 0;
}