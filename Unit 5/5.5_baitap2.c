#include <stdio.h>
#define MAX_NAME_LEN 100


typedef struct {
    char firstName[MAX_NAME_LEN];
    char middleName[MAX_NAME_LEN];
    char lastName[MAX_NAME_LEN];
    char birthDate[11]; 
} Profile;

int readProfile(Profile profiles[],char *filename){
    FILE * file = fopen(filename,"r");
    if (file == NULL) {
        fprintf(stderr,"Error opening file.\n");
        return 1;
    }

    int count = 0;
    while (fscanf(file,"%s %s %s %s", 
            profiles[count].firstName,
            profiles[count].middleName,
            profiles[count].lastName,
            profiles[count].birthDate,
            )==4 ){
                count++;
            
            }
    fclose(file);
    return count;
}

void printProfile(Profile profiles[],int count){
    for (int i = 0; i < count; i ++ ){
        printf("%s %s %s %s\n",
            profiles[count].firstName,
            profiles[count].middleName,
            profiles[count].lastName,
            profiles[count].birthDate);
    }
}

int main(){
    FILE * file = fopen("profile-n.txt","w");
    c = fscanf()
    while (fscanf(file,"%c"))



    fclose(file);

    return 0;
}