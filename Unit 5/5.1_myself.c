#include <stdio.h>
#include <time.h>

#define N 1000000

//create data
void dataCreate(){
    int n,m,M;
    int a[N];
    scanf("%d %d %d",&n,&m,&M);

    FILE * file = fopen("arr-n.txt","w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    srand(time(NULL));
    for (int i=0; i < n; i++){
        int random_num = rand()%(M-m+1)+m;
        fprintf(file,"%d",random_num);
        
    }
}

int main(){
    return 0;
}