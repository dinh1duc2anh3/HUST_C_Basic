//so thuc nhap tu nguoi dung, tra ve phan nguyen va phan thuc
#include <stdio.h>
#include <math.h>


void split(double num, int *integer_part, double *frac_part){
    *integer_part = (int)floor(num);
    *frac_part = num - *integer_part;
}

int main(){
    double realNum,fraction;
    int integer;   

	scanf("%lf",&realNum); //realNum
    split(realNum,&integer,&fraction); 
    // printf("the integer part of %.3lf is %d\n",realNum,integer);
    printf("the integer part of %.3lf is %d\n",realNum,(int)floor(realNum));
    printf("the fraction part of %.3lf is %.3lf",realNum,fraction);
	return 0;
}



