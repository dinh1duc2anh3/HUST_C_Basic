#include <stdio.h>
#include <stdbool.h>

// Hàm kiểm tra xem một số có phải là số nguyên tố hay không
bool isPrime(int n, int divisor) {
    if (n <= 2) {
        return (n == 2);
    }

    if (n % divisor == 0) {
        return false;
    }

    if (divisor * divisor > n) {
        return true;
    }

    return isPrime(n, divisor + 1);
}

// Hàm liệt kê số nguyên tố từ 2 đến n
void listPrimes(int n, int current) {
    if (current <= n) {
        if (isPrime(current, 2)) {
            printf("%d ", current);
        }
        listPrimes(n, current + 1);
    }
}

int main() {
    int n;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    printf("Cac so nguyen to tu 2 den %d la: ", n);
    listPrimes(n, 2);

    return 0;
}