#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define N 4

int x[N];

bool check(int k) {
    // Kiểm tra hàng ngang và hai đường chéo
    for (int i = 1; i < k; i++) {
        if (x[i] == x[k] || (x[i] -i == x[k] - k || x[i]+i == x[k] + k)) {
            return false;
        }
    }
    return true;
}

void printSolution() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
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

void Try(int k) {
    if (k > N) {
        printSolution();
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        x[k] = i;
        if (check(k)) {
            Try(k + 1);
        }
    }
}

int main() {
    int n;
    Try(1); // Bắt đầu từ hàng 1
    return 0;
}
