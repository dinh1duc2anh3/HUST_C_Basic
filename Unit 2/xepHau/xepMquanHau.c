//problem
#include <stdio.h>
#include <stdbool.h>

#define N 4
#define M 3 // Số lượng quân hậu cần đặt

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

bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Kiểm tra cùng một hàng
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Kiểm tra đường chéo trái phía trên
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Kiểm tra đường chéo trái phía dưới
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveMQueens(int board[N][N], int col, int m) {
    if (m == 0)
        return true;

    if (col >= N)
        return false;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveMQueens(board, col + 1, m - 1))
                return true;

            board[i][col] = 0; // Quay lui
        }
    }

    return solveMQueens(board, col + 1, m);
}

int main() {
    int board[N][N] = {0};

    if (solveMQueens(board, 0, M)) {
        printf("Solution exists:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
