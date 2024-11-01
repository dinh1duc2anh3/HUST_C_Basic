//doc xau nhap tu nguoi dung, hien thi moi tu trong cau tren 1 
//dong( 1 tu la day cac ky tu lien tiep khong chua khoang trang)

#include <stdio.h>
#include <string.h>
#define SIZE 100

char str[SIZE];

int check(int v){
    if (v > 1) return 0;
    return 1;
}

void word_devide(char s[SIZE]){
    int count = 0; // theo doi so lan lien tiep cua ky tu khoang trang
   // for (int i = 0; i < strlen(s); i++){
    for (int i =0; s[i] != '\0';i++){ 
        if (s[i] != ' ') {
            printf("%c",s[i]);
            count = 0;
        }
        else {
            count++;
            if (check(count)){
                printf("\n");
            }
        }
    }
}

int main(){
	fgets(str,sizeof(str),stdin);
    word_devide(str);
	return 0;
}



