#include <stdio.h>

#define N 100

int n;
int a[N];

//---------------------------------------------------------------


void input(FILE * fp){
    fscanf(fp,"%d",&n);
    for (int i = 1; i <= n ; i++){
        fscanf(fp,"%d",&a[i]);
    }
}

void processInput(){
    char * filename = "data.txt";
    FILE* fp = fopen(filename , "r");
    input(fp);
    fclose(fp);
    printf("Load successfully %s.\n",filename);
}

void swap(int* a, int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int a[], int n){
    for (int k = 1; k <= n; k ++){
        int min = k;
        for (int j = k+1; j <= n; j ++){
            if (a[j] < a[min] ) min = j;
        }
        swap(&a[min] , &a[k]);
    }
}

void printArray(int a[] , int n){
    for (int i = 1; i <= n; i ++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

//---------------------------------------------------------------


int main(){
    processInput();
    printf("array before sorting: ");
    printArray(a,n);
    selectionSort(a,n);
    printf("array after sorting: ");
    printArray(a,n);
    

}