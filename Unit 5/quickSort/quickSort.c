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

int partition( int a[] , int l , int r, int indexPivot){
    int pivot = a[indexPivot];
    swap (&a[indexPivot] , &a[r]);
    int storeIndex = l;
    for (int k = l ; k < r; k ++){
        if (a[k] < pivot ){
            swap(&a[k] , &a[storeIndex]);
            storeIndex++;
        }

    }
    swap(&a[storeIndex] , &a[r]);
    return storeIndex;
}


void quickSortMiddlePivot(int a[] , int l , int r){
    int indexPivot = (l + r)/2;
    indexPivot = partition(a , l , r , indexPivot);
    if (l < indexPivot ){
        quickSortMiddlePivot(a , l , indexPivot - 1 );

    }
    if ( indexPivot < r){
        quickSortMiddlePivot(a , indexPivot + 1 , r);
    }
}


void quickSortFirstPivot(int a[] , int l , int r ){
    int indexPivot = l;
    indexPivot = partition(a , l , r , indexPivot);
    if (l < indexPivot ){
        quickSortMiddlePivot(a , l , indexPivot - 1 );

    }
    if ( indexPivot < r){
        quickSortMiddlePivot(a , indexPivot + 1 , r);
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
    quickSortFirstPivot(a , 1 , n);

    printArray(a ,n);   
    end = clock();
    time_use = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Time used: %.4lf ms\n", time_use);

    return 0;
}