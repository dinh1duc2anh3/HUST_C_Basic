#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Hàm kiểm tra xâu đối xứng
bool isPalindrome(char str[], int left, int right) {
    // Khi chỉ còn một ký tự hoặc không còn ký tự nào
    if (left >= right) {
        return true;
    }

    // Nếu các ký tự tại vị trí left và right không khớp
    if (str[left] != str[right]) {
        return false;
    }

    // Kiểm tra xâu con bên trong
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    char str[] = "abcbade";

    int length = strlen(str);

    if (isPalindrome(str, 0, length - 1)) {
        
        printf("%s la xau doi xung.\n", str);
    } else {
        printf("%s khong phai la xau doi xung.\n", str);
    }

    return 0;
}