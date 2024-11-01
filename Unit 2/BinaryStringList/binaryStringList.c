/*Input: Binary string list */

#include <stdio.h>

#define SIZE 100

int x[SIZE];
int n;

void printSolution(){
    for(int i = 0; i < n; i++){
        printf("%d",x[i]);
    }
    
        printf("\n"); 
}

int Try(int k){
    for (int v = 0; v <= 1; v++){
        x[k] = v;
        if (k == n-1) printSolution();
        else Try(k+1);
    }
}

int main(){
    scanf("%d",&n);
    Try(0);


    return 0;
}