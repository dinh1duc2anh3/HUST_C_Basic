#include <stdio.h>

//copy each character

char UpperLowerCase(char c){
    if (c >= 'A' && c <= 'Z') {
        c = c + 32; // Convert to lowercase
    } else if (c >= 'a' && c <= 'z') {
        c = c - 32; // Convert to uppercase
    }
    return c;
}

int main(){
    char filename[] = "lab1.txt";
    char destFilename[] = "lab1w.txt";
    FILE* fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening %s", filename);
        return 1;
    }

    int c;
    FILE* fpdes = fopen(destFilename, "w");
    
    while ((c = fgetc(fp)) != EOF) {
        char newChar = UpperLowerCase(c);
        fputc(newChar, fpdes);
        printf("%c\n", newChar);
    }

    fclose(fpdes);
    fclose(fp);

    return 0;
}
