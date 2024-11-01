#include <stdio.h>

#define N 1000

void merge(int a[], int l, int m, int r) {
    int TA[r - l + 1];
    int i = l, j = m + 1;

    for (int k = 0; k <= r - l; k++) {
        if (i > m) {
            TA[k] = a[j];
            j++;
        } else if (j > r) {
            TA[k] = a[i];
            i++;
        } else if (a[i] < a[j]) {
            TA[k] = a[i];
            i++;
        } else {
            TA[k] = a[j];
            j++;
        }
    }

    for (int i = 0; i <= r - l; i++)
        a[l + i] = TA[i];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void print(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int n, a[N];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("Day truoc khi sap xep: ");
    print(a, n);
    printf("\n");
    mergeSort(a, 0, n - 1);
    printf("Day sau khi sap xep: ");
    print(a, n);
    return 0;
}
