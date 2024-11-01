#include <stdio.h>
#include <math.h>
double x,y,z,delta;
void ptbac2(double a,double b,double c){
	if (a==0) printf("x1=%.3lf",-c/b);
	else {
		delta=b*b-4*a*c;
		if (delta < 0) printf("VO NGHIEM");
		if (delta == 0) printf("%.4lf %.4lf",-b/(2*a),-b/(2*a));
		if (delta > 0) {
			printf("%.4lf ",(-b+sqrt(delta))/(2*a));
			printf("%.4lf\n",(-b-sqrt(delta))/(2*a));			
		}
	} 
}
 int main(){
 	scanf("%lf %lf %lf",&x,&y,&z);
 	ptbac2(x,y,z);
 	
 	return 0;
 }
