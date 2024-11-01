#include <stdio.h>
#define N 500

int blackColumn(int a[N][N], int columns, int rows) {
    int cnt = 0;
    for (int i = 0; i < columns; i++) {
        int row1Count = 0; // Đặt giá trị khởi tạo của row1Count ở đây
        for (int j = 0; j < rows; j++) {
            if (a[j][i] != 1) { // Chỉnh sửa điều kiện kiểm tra và chỉ số của mảng
                break;
            }
            row1Count++;
        }
        if (row1Count == rows) cnt++;
    }
    return cnt;
}

int main() {
    int m, n;
    scanf("%d %d", &n, &m);
    // n rows    m columns
    int a[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d", blackColumn(a, m, n));

    return 0;
}
