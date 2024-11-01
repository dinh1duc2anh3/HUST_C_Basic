#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(){
    char filename[10] = "lab1.txt";
    char destFilename[10] = "lab1w.txt";
    char str[SIZE];
    int len = 0;

    FILE * fp = fopen(filename, "r");
    
    FILE * fpdes = fopen(destFilename, "w");
    if (fp == NULL ){
        printf("Error opening %s",filename);
        fclose(fp);
        return 1;
    }

    if (fpdes == NULL ){
        printf("Error opening %s",destFilename);
        fclose(fpdes);
        return 1;
    }

    while (fgets(str,SIZE,fp) != NULL){
        len = strlen(str)-1 ;

            fprintf(fpdes,"%d %s ",len,str);
            printf("%d %s",len,str);

    }

    fclose(fpdes);
    fclose(fp);
    return 0;
}