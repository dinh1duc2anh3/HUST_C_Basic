#include <stdio.h>
#include <stdlib.h>

typedef struct phonebook{
    char name[20];
    char phoneNumber[20];
    char email[30];
} phonebook;


int main(){
    int n = 10;

    phonebook* phoneList = (phonebook* )malloc(n* sizeof (phonebook));


    FILE * fp = fopen("phonebook.txt" , "a+");
    int i = 0;
        while (fscanf(fp,"%s %s %s",
            phoneList[i].name,
            phoneList[i].phoneNumber,
            phoneList[i].email) == 3){
                fprintf(fp,"%d %s %s %s",i+1,phoneList[i].name,
                    phoneList[i].phoneNumber,
                    phoneList[i].email);
                i++;
            }
    fclose(fp);
    return 0;
}