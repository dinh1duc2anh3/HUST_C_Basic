#include <stdio.h>
#define SIZE 20
#define ALPHABET_LEN 26
char c,s[SIZE];
int count[ALPHABET_LEN];

void nl(){
	printf("\n");
}

void stringInput(){
	printf("nhap vao mot xau ky tu: (<= %d ky tu) ",SIZE);
	gets(s);   // s : char 20 
	//doc mot xau nhap vao tu ban phim ?
}

void letterFrequency(){
	for (int i = 0; i < ALPHABET_LEN ; i++) count[i] = 0; //khoi tao mang count
	
	for (int i = 0; i < SIZE ; i++) {
		c = s[i];
		if (c <= 'z' && c >= 'a' ) count[c-'a'] ++;
		if (c <= 'Z' && c >= 'A' ) count[c-'A'] ++;
		else { printf("hay nhap chu cai") ;
			break;
		}
	}
	
	for (int i = 0; i < ALPHABET_LEN ; i++ ) {
		if ( count[i] != 0 ) {
			printf("letter %c appears %d time(s) \n",'a'+i,count[i]);
		}
	}
}

int main (){
	stringInput();
	letterFrequency();
	
	return 0;
}
