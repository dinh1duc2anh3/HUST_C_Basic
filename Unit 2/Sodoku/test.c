#include <stdio.h>

#define N 9

int is_valid(int board[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }

    return 1;
}

void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int solve_sudoku(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= N; num++) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;

                        if (solve_sudoku(board)) {
                            // Nếu tìm thấy một giải pháp, in và tiếp tục tìm kiếm
                            print_board(board);
                        }

                        board[row][col] = 0;  // Quay lui
                    }
                }
                return 0;  // Nếu không có giá trị nào thích hợp, quay lui
            }
        }
    }

    return 1;  // Nếu đã điền tất cả các ô, trả về 1
}

int main() {
    int board[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (!solve_sudoku(board)) {
        printf("No solution exists.\n");
    }

    return 0;
}
