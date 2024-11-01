#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    double width, height;
    
    if (argc != 3) {
        printf("Sai số lượng tham số!\n");
        printf("CÚ PHÁP ĐÚNG: RECT <WIDTH> <HEIGHT>\n");
        return 1;
    }
    
    width = atof(argv[1]);
    height = atof(argv[2]);
    
    printf("Diện tích hình chữ nhật là %f\n", width * height);
    printf("Chu vi hình chữ nhật là %f\n", 2 * (width + height));
    
    return 0;
}