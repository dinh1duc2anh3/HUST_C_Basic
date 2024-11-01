#include <stdio.h>

#include <stdbool.h>


#define N 4
#define M 3

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // printf("%d ", board[i][j]);
            if (board[i][j] == 0) printf(". ");
            else printf("Q ");
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N] , int row, int col){

    for (int i = 0; i < col; i++){
        if (board[row][i]) return false;
    }

    for (int i = row, j = col; i>= 0 && j >= 0 ; i-- , j --){
        if (board[i][j]) return false;
    }

    for (int i = row , j = col ; i < N && j >= 0; j -- , i ++){
        if (board[i][j]) return false;
    }
    return true;
}

bool solveMQueens (int board[N][N] , int col , int m){
    if (m == 0) {
        return true;
    }

    if (col >= N){
        return false;
    }

    for (int row = 0; row < N ; row ++){
        if (isSafe(board , row ,col )){
            board[row][col] = 1;

            if (solveMQueens(board ,col + 1, m -1)){
                return true;
            }

            board[row][col] = 0; 
        }
    }
    return solveMQueens(board, col + 1, m);

}



int main(){
    int board[N][N] = {0};
    if (solveMQueens(board, 0, M)) {
        printf("Solution exists:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}