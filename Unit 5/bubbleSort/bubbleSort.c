#include <stdio.h>
#include <time.h>

#define N 10000

int n;
int a[N];
int cnt = 1;

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

void printArray(int a[] , int n){
    
        for (int i = 1; i <= n; i ++){
            printf("%d ",a[i]);
        }
        printf("\n");
    
    
}

void bubbleSort1(int a[] , int n){  //không dừng sort khi dãy đã được sắp xếp giứa chừng 
    printArray(a,n);
    for (int i = 1; i < n; i ++){
        for (int j = 1; j <= n -i ; j ++){
            if (a[j] > a[j+1]  ) {
                swap(&a[j] , &a[j+1]);
            }
        }
    }

}

void bubbleSort2(int a[],int n){    //sẽ dừng khi giữa chừng mà dãy đã được sắp xếp
    int swapped;
    do {
        int i = 1;
        swapped = 0;
        for (int j= 1; j <= n - i; j ++){
            if (a[j] > a[j+1]){
                swap(&a[j] , &a[j+1]);
                swapped = 1;
            }
        }
        i ++;
    }
    while ( swapped == 1);

}
//---------------------------------------------------------------


int main(){
    clock_t start , end;
    double  time_use;
    
    processInput();
    
    int b[N];
    for (int i = 1; i <= n ; i ++){
        b[i] = a[i];
    }
    printArray(b,n);

    start = clock();

    // bubbleSort1(a,n);
    bubbleSort2(b,n);
    printArray(b,n);
    end = clock();
    time_use = ((double) (end-start)/CLOCKS_PER_SEC) * 1000;

    printf("Time used: %.4lf ms.\n",time_use);


    return 0;
}