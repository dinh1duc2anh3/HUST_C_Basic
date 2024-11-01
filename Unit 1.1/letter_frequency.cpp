#include <stdio.h>
#include <string.h>
#define SIZE 10
#define ALPHABET_LEN 26
char s[20],c='\0';
int i,count[ALPHABET_LEN];

void nl(){
	printf("\n");
}

void stringInput(){
	printf("please enter a line of text: \n");
	gets(s);
}

void stringDisplay(){
	printf("string Display : \"");
	for (int i=0; i < SIZE; i++){
		printf("%c",s[i]);
	}
	printf("\"");
	nl();
}

void stringInit (){ // khoi tao mang 26 ky tu bang mang cac so 0;
	int count[ALPHABET_LEN] =  {0} ;
}

void letterFrequency(){
	for (int i =0; i < ALPHABET_LEN; i++){
		c = s[i];
		if (c <= 'z' && c >= 'a') { count[c-'a']++;
		}
	    if (c <= 'Z' && c >= 'A'){ count[c-'A']++;
		}
	}	
	c='a';
	for (int i =0; i<ALPHABET_LEN; i++){
		if (count[i] > 0) {
			printf("The letter '%c' appears %d time(s).\n",c+i,count[i]);
		}
	}
}

int main(){
	stringInput();
	stringDisplay();
	stringInit();
	letterFrequency();
	
	return 0;
}
