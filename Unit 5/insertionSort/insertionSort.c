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

void insertionSort(int a[] , int n){
    //index 1-> n
    for (int k = 2; k <= n; k ++){
        int last = a[k];
        int j = k;
        while (j > 1 && a[j-1] > last){
            a[j] = a[j-1];
            j--;
        }
        a[j] = last;
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
    insertionSort(a,n);
    printf("array after sorting: ");
    printArray(a,n);
    

}