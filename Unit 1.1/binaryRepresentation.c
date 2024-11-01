#include <stdio.h>
#define MAX 100

void Binary(int n) {
    int binary[MAX];
    int i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

void GenerateBinary(int n) {
    for (int i = 1; i <= n; i++) {
        printf("Binary representation of %d: ", i);
        Binary(i);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    GenerateBinary(n);
    return 0;
}