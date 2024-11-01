#include <stdio.h>
int main (){
    char ch1,ch2;
    printf("input the first character: ");
    scanf("%c,&ch1");
    printf("input the second character: ");
    ch2 = getchar();
    printf("character %c has the ascii code is %d",ch1,ch1);
    printf("character %c has the ascii code is %d",ch2,ch2);

    return 0;
}