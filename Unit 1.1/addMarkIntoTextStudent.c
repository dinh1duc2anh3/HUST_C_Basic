#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien{
    int STT;
    char MSSV[20];
    char HoTen[50];
    char SDT[15];
    float Diem;
};


int main (){
    int n = 0;
    FILE *fileIn , *fileOut;
    struct SinhVien dsSinhVien[100];

    fileIn = fopen("danhsachlop.txt","r");
    if (fileIn == NULL){
        printf("khong the mo file danhsachlop.txt \n");
        return 1;
    }

    while (fscanf(fileIn, "%d %s %s %s",&dsSinhVien[n].STT, dsSinhVien[n].MSSV, dsSinhVien[n].HoTen, dsSinhVien[n].SDT) != EOF)
        {
            n++;
        }

    fclose(fileIn);

    for (int i = 0; i < n ; i++){
        printf("nhap diem cho sinh vien %s: ",dsSinhVien[i].HoTen);
        scanf("%f",&dsSinhVien[i].Diem);
    }

    fileOut = fopen("bangdiem.txt","w");
    if (fileOut == NULL) {
        printf("khong the mo file bangdiem.txt");
        return 1;
    }

    for (int i = 0; i<n ; i++){
        fprintf(fileOut,"%d %s %s %s %.2f\n",dsSinhVien[i].STT,dsSinhVien[i].MSSV,dsSinhVien[i].HoTen,dsSinhVien[i].SDT,dsSinhVien[i].Diem);

    }
    fclose(fileOut);
    printf("da ghi thong tin vao bangdiem.txt");
    
    return 0;
}