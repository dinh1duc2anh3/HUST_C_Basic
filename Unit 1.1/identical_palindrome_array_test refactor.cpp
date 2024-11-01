#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

int a[SIZE],b[SIZE];

void arrayInput(){
	printf("nhap mang a co %d so: ",SIZE);
	for (int i = 0; i < SIZE; i++) scanf("%d",&a[i]);
	printf("\n");
	printf("nhap mang b co %d so: ",SIZE);
	for (int i = 0; i < SIZE; i++) scanf("%d",&b[i]);
	
}

int arrayIdentical(int arr1[SIZE],int arr2[SIZE]){
	int identical = 1;
	for (int i = 0; i < SIZE ; i++){
		if (arr1[i] != arr2[i]){
			identical = 0;
			break;
		}
	}
	return identical;
}

bool arrayPalindrome(int arr1[SIZE],int arr2[SIZE]){
	int i = 0,j = SIZE -1;
	while (i<j){
		if (arr1[i] != arr2[j]){
			return false;
		}
		i++;
		j--;	
	}
	return true;
}
	
int main(){
	arrayInput();
	if (arrayIdentical(a,b)) printf("hai mang giong nhau");
	if (arrayPalindrome(a,b)) printf("hai mang doi xung");
	
	return 0;
}
