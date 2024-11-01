#include <stdio.h>
#define SIZE 3

int i,sum,v;
double avg,min;
int a[SIZE],distance[SIZE];

void nl(){
	printf("\n");
}

void Arrayinput (){
	for (int i = 0; i < SIZE ; i++) {
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
		nl();
	}
}

int average(){
	for (int i= 0; i<SIZE;i++){
		sum = sum +a[i];
	}
		avg= double(sum) / 3.0;
		return avg;
}
int minDistance(){
	for (int i=0;i<SIZE;i++){
		if (a[i] > avg) distance[i]= a[i]-avg;
		else distance[i]=avg-a[i];
	}
	
	min=distance[0];
	for (int i=1;i<SIZE;i++){
		if (distance[i] < min) {
			min = distance[i];
			v=i;
		}
	}
	return v;
}

int main (){
	Arrayinput();
	average();
	printf("phan tu co gia tri gan tb nhat la a[%d] = %d",minDistance(),a[minDistance()]);
	
	return 0;
}
