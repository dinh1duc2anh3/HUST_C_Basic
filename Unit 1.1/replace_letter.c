#include <stdio.h>
#include <string.h>

#define SIZE 20

char s[SIZE],a,b;

void replace_letter(char s[SIZE],char a,char b){
    for (int i = 0; i < strlen(s); i++){
        if (s[i] == a) s[i] = b;
    }
    printf("%s",s);

}

int main(){
    scanf("%s %c %c",s,&a,&b);

    replace_letter(s,a,b);
    return 0;
}