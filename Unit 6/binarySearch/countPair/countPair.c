/*Để tìm số cặp (ai, aj) trong dãy số a1, a2, ..., aN 
sao cho ai + aj = b (i < j), chúng ta có thể sử dụng thuật toán tìm kiếm nhị phân*/


#include <stdio.h>
#include <time.h>

#define N 1000

int n;
int a[N];
int ta[N]; // mảng trung gian để lưu dãy merge
int visited[N];
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
void merge(int a[] , int l , int m , int r){
    int i = l;
    int j = m+1;
    for (int k = l; k <= r; k ++){
        if (i > m) {
            ta[k] = a[j];
            j++;
        }
        else if (j > r){
           ta[k] = a[i];
           i++;
        }
        else if (a[i] < a[j]) {
            ta[k] = a[i];
            i++;
        }
        else {
            ta[k] = a[j];
            j++;
        }
    }
    for (int i = l; i <= r; i ++){
        a[i] = ta[i];
    }
}


void mergeSort( int a[] , int l , int r){
    if (l < r){
        int m = (l+r) /2;
        mergeSort(a, l , m);
        mergeSort(a, m+1 , r);
        merge(a, l , m , r);
    }
}


//---------------------------------------------------------------

int binarySearch(int a[] , int l , int r , int y){
    if (l == r) {
        if (a[l] == y) return l;
        return -1;
    }

    int mid = (l + r)/2;
    if (a[mid] < y) return binarySearch(a, mid+1 , r , y);
    return binarySearch(a , l , mid-1 , y);
}


//---------------------------------------------------------------

void countPair(int a[] , int b){
    int result;
    int cnt = 0;
    for (int k = 1; k <= n; k ++){
        result = binarySearch(a, 1, n, b- a[k]);
        if (result != -1){
            cnt++;
            printf("(%d,%d)\n",a[k] , b - a[k]);
        }
    }
    printf("tong so cap = %d\n",cnt);
}



void processCountPair(){
    int b;
    printf("Nhap b = ");
    scanf("%d" , &b);
    countPair(a, b);
}


//---------------------------------------------------------------

int main(){
    int num;
    processInput();
    printArray(a,n);
    


    // quickSortMiddlePivot(a, 1 , n);
    mergeSort(a , 1 , n);

    printArray(a ,n);   

    processCountPair();

    return 0;
}