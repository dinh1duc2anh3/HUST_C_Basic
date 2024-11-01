#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        printf("Sử dụng: %s <giá trị lũy thừa> [sai số cho phép]\n", argv[0]);
        return 1;
    }

    double x = atof(argv[1]);
    double epsilon = (argc == 4) ? atof(argv[2]) : 0.0001;

    double result = 1.0;
    double term = 1.0;
    int n = 1;

    while (fabs(term) >= epsilon) {
        term *= x / n;
        result += term;
        n++;
    }

    printf("e^%lf = %lf\n", x, result);

    return 0;
}
