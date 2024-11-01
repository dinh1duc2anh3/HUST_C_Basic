/*
Bài toán phân tích số nguyên dương thành tổng các số nguyên dương có thể

M: Số nguyên dương cần phân tích.
A[]: Mảng chứa các số nguyên dương có thể sử dụng để phân tích M.
X[]: Mảng chứa số lượng của mỗi số nguyên dương từ tập A trong phân tích.
N: Số lượng phần tử trong tập A.
currentN: Biến theo dõi vị trí hiện tại trong tập A.

*/


#include <stdio.h>
#define SIZE 100


void printSolution(int x[], int N){
    for (int i = 0; i < N; i ++){
        printf("X%d = %d, ",i+1, x[i]);
    }
    printf("\n");
}

void findSolutions(int M, int A[], int x[], int N, int currentN){
    if (M == 0){
        printSolution(x,N);
        return ;
    }

    if (currentN >= N || M < 0){
        return ;
    }

    for (int i= 0; i <= M/A[currentN] ; i ++ ){
        x[currentN] = i;
        findSolutions(M - i * A[currentN], A, x, N, currentN+1);
    }
}

int main(){
    int M = 10;
    int A[] = {2, 3, 5};
    int N = sizeof(A) / sizeof(A[0]);
    int x[N];

    findSolutions(M, A, x, N, 0);

    return 0;
}