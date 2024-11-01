/*hoán vị của dãy số nguyên n số sao cho không có hai số 
chẵn hoặc hai số lẻ đứng cạnh nhau*/
#include <stdio.h>
#define SIZE 10

int n;
int x[SIZE];
int visited[SIZE];

int check(int a, int b) {
    return (a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0);
}

void printSolution() {
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int Try(int k) {
    for (int v = 1; v <= n; v++) {
        if (visited[v] == 0) {
            // Kiểm tra điều kiện để đảm bảo số chẵn và lẻ xen kẽ nhau
            if (k == 0 || check(x[k - 1], v)) {
                x[k] = v;
                visited[v] = 1;

                // Nếu đã điền đầy đủ giá trị, in kết quả
                if (k == n - 1) {
                    printSolution();
                } else {
                    // Gọi đệ quy để thử các giá trị cho vị trí kế tiếp
                    Try(k + 1);
                }

                // Hoàn tác để thử các giá trị khác
                visited[v] = 0;
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    if (n < 1 || n > 9) {
        printf("n phai nam trong khoang tu 1 den 9.\n");
        return 1;
    }

    // Init
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Bắt đầu thử các giá trị
    Try(0);

    return 0;
}
