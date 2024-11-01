#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main(){
    int a[SIZE];
    int i , n, *p;
    printf("how many number do you want to enter?\n"); //can bao nhieu ptu cho  mang p
    //dau vao cua ham malloc la tinh theo byte thi can chuyen doi tu so so nguyen sang so byte cua n so nguyen
    //ham malloc tra ve void ( khong co cau truc) , khogn truy nhap duoc phan tu thu 1 hay 2 hay .. cua mot bien thuoc cau truc void
    //-> giai phap la cta se ep kieu int * cho ham malloc va con tro p ( tu void * q sang int * p = q) -> no se duoco tai cau truc thanh ham co cau truc

    scanf("%d",&n);
     p = (int *)malloc(n* sizeof(int));
     if (p == NULL){
        printf("memory allocation failed.\n");
        return 1;
     }
    for (int i =0; i < n ; i++){
        scanf("%d ",&a[i]);
    }
    
    //thuong gap loi cap phat bo nho dong xo gkhong giai phong ( khong free ) -> sau 1 tgian ram se het
    //loi cap phat ram thieu -> ctrinh loi 
    // sau nay hoc them thi nhieu loi nua
    // ram bi phan manh

    //mot mang so nguyen cx chinh la cmot con tro chi toi phantu dau tien
    //*p cx la mot con tro chi toi phan tu dau tien 
    for (int i = n-1; i >= 0; i++){
        printf("%d ",a[i]);
    }
    free(p);
    return 0;
}
//ham realloc co kha nang khogn cap phat duoc bo nho
