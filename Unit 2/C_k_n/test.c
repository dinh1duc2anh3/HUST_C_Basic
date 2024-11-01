#include <stdio.h>
#include <stdlib.h>

void freeMemoArray(int** m, int n) {
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

int C(int** m, int k, int n) {
    if (m[k][n] == -1) {
        if (k == 0 || k == n) {
            return 1;
        }

        m[k][n] = C(m, k, n - 1) + C(m, k - 1, n - 1);
        return m[k][n];
    } else {
        return m[k][n];
    }
}

int main() {
    int rows, cols; 
    scanf("%d %d", &rows, &cols);

    int** memoArray = (int**)malloc((rows + 1) * sizeof(int*));
    for (int i = 0; i < rows + 1; i++) {
        memoArray[i] = (int*)malloc((cols + 1) * sizeof(int));
    }

    // Khởi tạo
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            memoArray[i][j] = -1;
        }
    }

    printf("C[%d][%d] : %d ",rows,cols, C(memoArray, rows, cols));

    freeMemoArray(memoArray, rows + 1);
    return 0;
}
