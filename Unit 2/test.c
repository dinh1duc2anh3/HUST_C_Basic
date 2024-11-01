#include <stdio.h>

#define SIZE 100

int k, n, i, j;
int m[SIZE][SIZE];

void check(int i, int j) {
    if (m[i][j] != 0) 
        printf("da nho c(%d,%d) = %d\n", i, j, m[i][j]);
    else 
        printf("chua nho c(%d,%d) = %d\n", i, j, m[i][j]);
}

int c(int k, int n) {
    if (k == 0 || k == n) {
        m[k][n] = 1;
        check(k, n);
        return m[k][n];
    }

    m[k][n] = c(k - 1, n - 1) + c(k, n - 1);
    check(k, n);
    return m[k][n];
}

int main() {
    printf("k n = ?");
    scanf("%d %d", &k, &n);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) 
            m[i][j] = 0;
    }

    printf("ket qua la : %d ", c(k, n));
    return 0;
}
