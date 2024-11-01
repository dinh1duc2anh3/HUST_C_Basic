#include <stdio.h>
#define SIZE 3
int i,v,n,a[SIZE],b[SIZE];

void nl(){
	printf("\n");
}

void arrayInput(){
	printf("nhap day a gom %d so: ",SIZE);
	for (int i = 0; i<SIZE ; i++){
		scanf("%d",&a[i]);
	}
	nl();
	printf("nhap day b gom %d so: ",SIZE);
	for (int i = 0; i<SIZE ; i++){
		scanf("%d",&b[i]);
	}
}

int SimilarityTest(){
	for (int i=0;i<SIZE;i++){
		if (a[i] == b[i]) {
			v++;
		}
	}
	if (v == SIZE) return 1;
	return 0;
}

int SimmetryTest(){
	v = 0;
	for (int i=0;i<= (double(SIZE)/2) -1 ;i++){
		if (a[i] == b[SIZE-i-1]) {
			v++;
		}
	}
	if (SIZE % 2 == 0) {if (v == SIZE / 2) return -1;
	}
	else {
		if (v == (SIZE - 1)/2) return -1;
	}
	return 0;
}

int main(){
	arrayInput();
	if (SimilarityTest()) printf("hai mang trung nhau.");
	else if (SimmetryTest()) printf("hai mang doi xung nhau.");
	else printf("hai mang khong co mqh");
	return 0;
}
