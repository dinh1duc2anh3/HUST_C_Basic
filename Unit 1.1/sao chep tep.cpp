#include <stdio.h>

int main() {
    FILE *source_file, *destination_file;
    char ch;

    source_file = fopen("lab1.txt", "r");
    if (source_file == NULL) {
        printf("Khong the mo tep lab1.txt de doc.\n");
        return 1;
    }

    destination_file = fopen("lab1w.txt", "w");
    if (destination_file == NULL) {
        printf("Khong the mo tep lab1.txt de ghi.\n");
        fclose(source_file); 
        return 1;
    }

    
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, destination_file);
    }

    
    fclose(source_file);
    fclose(destination_file);

    printf("Da sao chep noi dung tu lab1.txt vào lab1w.txt\n");

    return 0;
}
