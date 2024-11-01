#include <stdio.h>
#include <time.h>

#define N 1000

int n;
int a[N];
int ta[N]; // mảng trung gian để lưu dãy merge
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

int main(){

    processInput();
    printArray(a,n);
    

    clock_t start, end;
    double time_use;


    start = clock();

    mergeSort(a, 1, n);

    printArray(a ,n);   
    end = clock();
    time_use = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Time used: %.4lf ms\n", time_use);

    return 0;
}