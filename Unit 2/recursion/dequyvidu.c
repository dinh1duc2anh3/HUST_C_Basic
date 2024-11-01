#include <stdio.h>
#include <math.h>
#define N 100

int v,n,i,j;

int f(int n){
	if (n == 1) return 1;
	printf("lan thu %d\n",n);
	return n + f(n-1);
}


int main(){
	printf("%d",f(3));
	return 0;
}


