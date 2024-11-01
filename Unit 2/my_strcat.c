#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

char *my_strcat (char *str1,char *str2){
    int len1,len2;
    char *result;

    len1 = strlen(str1);
    len2 = strlen (str2);

    result = (char * )malloc((len1 + len2 + 1)*sizeof(char))
    if (result == NULL){
        printf("Allocation failed. Check memory!");
        return NULL;
    }

    strcpy(result, str1);//copy len1 phan tu dau vao xau result
    strcpy(result + len1, str2); // copy len 2 ptu vao zau result ke tu vij tri len1
    //do dang thuc hanh cap phat bo nho dong nen khogn dung strcat
    //thuc chat strcat cung thuc hien cap phat bo nho dong nhu nay

    return result;
}

int main(){
    char s1[MAX_LEN],s2[MAX_LEN], *catstr;
    //ban chat mang la 1 con tro ke ca dong hay tinh
    printf("nhap xau 1: "); scanf("%100s",s1);
    printf("nhap xau 2: "); scanf("%100s",s2);
    catstr = my_strcat(s1,s2);
    if (catstr == NULL ){
        printf("problem allocating memory! ");
        return 1;
    }

    printf("the concatenation of %s and %s is %s \n",s1,s2,catstr);

    free(catstr);
    //dam bao ket thuc chuong trinh sau khi da gia phong bo nho neu nhu cap bo nho dong thanh cong
    //con neu chua cap bo nho dong thanh cong thi khogn can free
    return 0;
}
//