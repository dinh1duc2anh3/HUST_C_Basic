#include <stdio.h>
#include <stdbool.h>


#define N 4
int x[N];

int check(int v, int k) {
// kiểm tra xem v có thể gán được
// cho x[k] không
for(int i = 1; i <= k-1; i++) {
if(x[i] == v) return 0;
if(x[i] + i == v + k) return 0;
if(x[i] - i == v - k) return 0;
}
return 1;
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

void TRY(int k) {
for(int v = 1; v <= N; v++) {
if(check(v,k)) {
x[k] = v;
if(k == N) printSolution();
else TRY(k+1);
}
}
}
int main() {
TRY(1);
}
