#include <stdio.h>
#include <string.h>

// Hàm đảo ngược xâu sử dụng đệ quy
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return; // Điều kiện dừng đệ quy
    }

    // Hoán đổi ký tự tại vị trí start và end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Gọi đệ quy trên xâu con bên trong
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[] = "abcdef";
    int length = strlen(str);

    printf("Xau ban dau: %s\n", str);

    reverseString(str, 0, length - 1);

    printf("Xau sau khi dao nguoc: %s\n", str);

    return 0;
}
