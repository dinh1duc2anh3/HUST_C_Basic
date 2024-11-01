#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Sử dụng: %s <tập_tin_1> <tập_tin_2>\n", argv[0]);
        return 1;
    }

    char *tập_tin_1 = argv[1];
    char *tập_tin_2 = argv[2];

    FILE *file_1 = fopen(tập_tin_1, "a");
    if (file_1 == NULL) {
        perror("Lỗi khi mở tập tin thứ nhất");
        return 1;
    }

    FILE *file_2 = fopen(tập_tin_2, "r");
    if (file_2 == NULL) {
        perror("Lỗi khi mở tập tin thứ hai");
        fclose(file_1);
        return 1;
    }

    char ch;
    while ((ch = fgetc(file_2)) != EOF) {
        fputc(ch, file_1);
    }

    fclose(file_1);
    fclose(file_2);

    printf("Ghép nội dung từ %s vào cuối %s thành công\n", tập_tin_2, tập_tin_1);

    return 0;
}