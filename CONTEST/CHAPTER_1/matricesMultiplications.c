#include <stdio.h>

int main() {
    // Read dimensions of matrix A
    int n, k;
    scanf("%d %d", &n, &k);

    // Read matrix A
    int A[n][k];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read dimensions of matrix B
    int m;
    scanf("%d %d", &k, &m);

    // Read matrix B
    int B[k][m];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Compute the product matrix C
    int C[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
            for (int x = 0; x < k; x++) {
                C[i][j] += A[i][x] * B[x][j];
            }
        }
    }

    // Print the resulting matrix C
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", C[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
