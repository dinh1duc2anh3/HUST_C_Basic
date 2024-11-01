#include <stdio.h>
#include <time.h>

#define N 1000

int n;
int a[N];
int ta[N]; // mảng trung gian để lưu dãy merge
int cnt = 1;

//---------------------------------------------------------------


void swap(int* a, int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


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

void printArray(int a[] , int n){
    
        for (int i = 1; i <= n; i ++){
            printf("%d ",a[i]);
        }
        printf("\n");
    
    
}
//---------------------------------------------------------------

void heapify(int a[] , int i, int n){
    int l = 2*i;
    int r = 2*i + 1;
    int max = i;
    if (l <= n){
        if (a[l] > a[i]) max = l; 
    } 
    if (r <= n){
        if (a[r] > a[max] ) max = r;
    }
    if (max != i) {
        swap(&a[i] , &a[max]);
        heapify(a, max , n);
    }
}

void buildHeap(int a[] , int n){
    for (int i = n/2 ; i >= 1; i --){
        heapify(a , i , n);
    }
}


void heapSort(int a[] , int n){
    buildHeap(a , n);
    for( int i = n; i > 1; i --){
        swap(&a[i] , &a[1]);
        buildHeap(a , i-1);
    }
}
//---------------------------------------------------------------

int main(){

    processInput();
    printArray(a,n);
    

    clock_t start, end;
    double time_use;


    start = clock();
    // quickSortMiddlePivot(a, 1 , n);
    heapSort(a , n);
    printArray(a ,n);   

    end = clock();
    time_use = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Time used: %.4lf ms\n", time_use);

    return 0;
}