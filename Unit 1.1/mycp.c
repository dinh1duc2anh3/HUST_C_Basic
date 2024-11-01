#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Su dung: %s <tap_tin_nguon> <tap_tin_dich>\n", argv[0]);
        return 1;
    }

    FILE *source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        perror("Loi khi mo tap tin nguon");
        return 1;
    }

    FILE *destination_file = fopen(argv[2], "w");
    if (destination_file == NULL) {
        perror("Loi khi mo tap tin dich");
        fclose(source_file);
        return 1;
    }

    char ch;
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    printf("Sao chep thanh cong tu %s sang %s\n", argv[1], argv[2]);

    return 0;
}