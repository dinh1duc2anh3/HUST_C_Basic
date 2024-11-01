#include <stdio.h>
#include <stdlib.h>

// Hàm so sánh để sử dụng trong qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void findPairBinarySearch(int arr[], int n, int Q) {
    for (int i = 0; i < n; i++) {
        int complement = Q - arr[i];
        int j = binarySearch(arr, i + 1, n - 1, complement);
        if (j != -1) {
            printf("Binary Search: Pair found at indices %d and %d\n", i + 1, j + 1);
            return;
        }
    }
    printf("Binary Search: No pair found.\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int Q = 9;

    // Sắp xếp mảng để sử dụng tìm kiếm nhị phân
    qsort(arr, n, sizeof(int), compare);

    findPairBinarySearch(arr, n, Q);

    return 0;
}
