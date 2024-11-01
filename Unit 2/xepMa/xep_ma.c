#include <stdio.h>
#include <stdbool.h>

#define N 10 // Chessboard size

int board[N][N] = {0}; // NxN chessboard
int solutions = 0;

bool is_safe(int row, int col) {
    int i, j;

    // Check horizontally
    for (i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower left diagonal
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void print_board() {
    int i, j;
    printf("Solution %d:\n", solutions++);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool solve_nqueens(int col) {
    if (col >= N) {
        print_board();
        return true;
    }

    bool res = false;
    int i;
    for (i = 0; i < N; i++) {
        if (is_safe(i, col)) {
            board[i][col] = 1;
            res = solve_nqueens(col + 1) || res;
            board[i][col] = 0; // Backtracking
        }
    }

    return res;
}

int main() {
    int M;

    printf("Enter the number of knights (M): ");
    scanf("%d", &M);

    if (M > N) {
        printf("No valid solution.\n");
        return 1;
    }

    if (solve_nqueens(0) == false) {
        printf("No valid solution.\n");
    }

    return 0;
}
