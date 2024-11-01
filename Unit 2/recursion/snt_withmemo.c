#include <stdio.h>
#include <stdbool.h>

#define MAX_N 1000

// Mảng để lưu trữ kết quả kiểm tra số nguyên tố
bool isPrimeMemo[MAX_N];

// Khởi tạo mảng isPrimeMemo với giá trị false
void initializeMemoization() {
    for (int i = 0; i < MAX_N; i++) {
        isPrimeMemo[i] = false;
    }
}

// Hàm kiểm tra xem một số có phải là số nguyên tố hay không
bool isPrime(int n) {
