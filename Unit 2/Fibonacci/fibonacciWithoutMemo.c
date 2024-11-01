#include <stdio.h>

int Fibonacci(int k){
    if (k == 0) return 0;
    if (k== 1 ) return 1;
    return Fibonacci(k-1) + Fibonacci(k-2);
}

int main(){
    printf("F(%d) =  %d\n",3,Fibonacci(3));
    return 0;
}