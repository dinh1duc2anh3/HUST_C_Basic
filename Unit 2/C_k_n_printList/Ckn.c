/*viết tổ hợp chập k của n ra */

#include <stdio.h>
#define SIZE 100
int x[SIZE],a[SIZE];
int n,k;

void printSolution(){
    for (int i = 1; i <=k ; i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}

int TRY(int i) {
    for(int v = x[i-1]+1; v <= n-k+i; v++){
        x[i] = v;
        if(i == k) 
        printSolution();
        else TRY(i+1);
    }
}
int main() {
    
    n=5;k=3;
    x[0] = 0;
    TRY(1);
}
