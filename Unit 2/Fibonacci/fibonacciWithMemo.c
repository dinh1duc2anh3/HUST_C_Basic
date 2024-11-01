#include <stdio.h>
#include <stdlib.h>


int Fibonacci(int* Fibo, int k){
    if ( Fibo[k] == -1)
        {if (k == 0) return 0;
        if (k== 1 ) return 1;
        Fibo[k] = Fibonacci(Fibo,k-1) + Fibonacci(Fibo,k-2);
        }
    return Fibo[k];
}

int main(){ 
    int n;
    scanf("%d",&n);

    int* F = (int*)malloc( (n+1)* sizeof(int) );

    for (int i = 0; i <=n ; i++){
        F[i] = -1;
    }

    printf("F(%d) =  %d\n",n,Fibonacci(F,n));



    free(F);
    return 0;
}