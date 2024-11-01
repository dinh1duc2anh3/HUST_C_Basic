#include <stdio.h>

#define N 4


int x[N]; // Mảng lưu vị trí quân hậu trên mỗi hàng

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (x[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int check(int row, int col) {
    // Kiểm tra xem vị trí (row, col) có bị xung đột với các quân hậu đã đặt trước đó hay không

    for (int i = 0; i < row; i++) {
        if (x[i] == col ||                  // Kiểm tra xung đột theo cột
            x[i] - i == col - row ||        // Kiểm tra xung đột theo đường chéo chính
            x[i] + i == col + row) {        // Kiểm tra xung đột theo đường chéo phụ
            return 0;
        }
    }

    return 1;
}

void placeQueens(int row, int m) {
    if (m == 1) {
        printSolution();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (check(row, col)) {
            x[row] = col;
            placeQueens(row + 1, m - 1);
        }
    }
}

int main() {
    int M;
    printf("Enter the number of queens (M): ");
    scanf("%d", &M);

    placeQueens(0, M);

    return 0;
}