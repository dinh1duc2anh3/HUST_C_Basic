#include <stdio.h>
#include <stdlib.h>

typedef struct Profile {
    int stt;
    char mssv[10];
    char name[15];
    char phoneNumber[15];
    double grade;
} Profile;

int main() {
    int n;
    char filename[30] = "addMarkIntoTextStudent.txt";
    char filenamedes[20] = "bangdiem.txt";

    scanf("%d", &n);
    Profile* Student = (Profile*)malloc(n * sizeof(Profile));

    for (int i = 0; i < n; i++) {
        printf("nhap diem cho student %d: ", i + 1);
        scanf("%lf", &Student[i].grade);
    }

    FILE* fp = fopen(filename, "r");
    FILE* fpdes = fopen(filenamedes, "w");

    int i = 0;
    while (i < n && fscanf(fp, "%d %s %s %s",
        &Student[i].stt,
        Student[i].mssv,
        Student[i].name,
        Student[i].phoneNumber) == 4) {
        fprintf(fpdes, "%d %s %s %s %.2lf\n",
            Student[i].stt,
            Student[i].mssv,
            Student[i].name,
            Student[i].phoneNumber,
            Student[i].grade);
        i++;
    }

    fclose(fpdes);
    fclose(fp);
    free(Student);

    return 0;
}
