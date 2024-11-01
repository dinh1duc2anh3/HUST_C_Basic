#include <stdio.h>

#define SIZE 100
//copy each character

// char UpperLowerCase(char c){
//     if (c >= 'A' && c <= 'Z') {
//         c = c + 32; // Convert to lowercase
//     } else if (c >= 'a' && c <= 'z') {
//         c = c - 32; // Convert to uppercase
//     }
//     return c;
// }

int main(){
    char filename[] = "lab1.txt";
    char destFilename[] = "lab1w.txt";
    FILE* fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening %s", filename);
        return 1;
    }

    char str[SIZE];
    FILE* fpdes = fopen(destFilename, "w");
    int count = 0;

    while (fgets(str,SIZE,fp) != NULL) {
        count++;
        fprintf(fpdes,"Line %d : ",count);
        fputs(str,fpdes);
    }

    fclose(fpdes);
    fclose(fp);

    return 0;
}
