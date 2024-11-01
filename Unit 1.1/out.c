#include <stdio.h>

#include <stdlib.h>

#define N 30
int main() {
    int n,sum = 0;
    scanf("%d",&n);
    int* a = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i ++){
        scanf("%d",&a[i]);
        sum += a[i];
    }

    char filename[10] = "out.txt";
    FILE* fp = fopen(filename,"w");
        fprintf(fp,"%d ",n);
        for (int i = 0; i < n; i++){
            fprintf(fp,"%d ",a[i]);
        }
        fprintf(fp,"%d ",sum);
    fclose(fp);

    return 0;
}
