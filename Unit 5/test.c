#include <stdio.h>
#include <string.h>

typedef struct Profile{
    char  ho[10];
    char tenDem[10];
    char ten[10];
    int year;
    int month;
    int day;
} Profile;

Profile * studentProfile;

void readProfile(filename){
    int line = 0;
    FILE* fp = fopen (filename , "r");
    while (fscanf(fp , "%s %s %s %s-%s-%s" ,& ))
    fclose (fp);
}


int main(){

    return 0;
}