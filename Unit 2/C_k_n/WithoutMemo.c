/*Input: tính Ckn dùng đệ quy không nhớ
biết C[k][n] = C[k][n-1] + C[k-1][n-1]
C[0][n] = 0
C[n][n] = 0
*/
 
#include <stdio.h>

int C(int k, int n){
    if (k == 0 || k == n) {
        return 1;

    }
    return C(k,n-1) + C(k-1,n-1);
}

int main(){
    printf("%d\n",C(3,5));
    return 0;
 }