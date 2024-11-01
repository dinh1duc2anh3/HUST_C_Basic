#include <stdio.h>
#include <stdbool.h>

#define N 9

// Hàm in ra bàn cờ Sudoku
void print_board(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d ", board[row][col]);
        }
        printf("\n");
    }
}

// Hàm kiểm tra xem có thể đặt giá trị 'num' vào ô (row, col) không
bool is_safe(int board[N][N], int row, int col, int num) {
    // Kiểm tra hàng và cột
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }

    // Kiểm tra trong ô 3x3 con
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Hàm giải bài toán Sudoku bằng quay lui
bool solve_sudoku(int board[N][N]) {
    int row, col;

    // Tìm ô chưa điền (0)
    bool empty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty) {
            break;
        }
    }

    // Nếu không còn ô trống, bài toán đã được giải
    if (!empty) {
        return true;
    }

    // Đặt giá trị từ 1 đến 9 vào ô (row, col) nếu hợp lệ
    for (int num = 1; num <= 9; num++) {
        if (is_safe(board, row, col, num)) {
            board[row][col] = num;

            // Nếu giải tiếp tục thành công, trả về true
            if (solve_sudoku(board)) {
                return true;
            }

            // Nếu không thành công, hủy bỏ và thử giá trị khác
            board[row][col] = 0;
        }
    }

    // Nếu không có giá trị nào phù hợp, trả về false
    return false;
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solve_sudoku(board)) {
        printf("Sudoku solution:\n");
        print_board(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
