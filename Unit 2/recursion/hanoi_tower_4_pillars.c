#include <stdio.h>

void hanoi_4_colums(int n, char source, char auxiliary1, char auxiliary2, char target) {
    if (n == 1) {
        printf("Di chuyen dia tu cot %c sang cot %c\n", source, target);
        return;
    }
    hanoi_4_colums(n - 1, source, auxiliary2, auxiliary1, target);
    printf("Di chuyen dia tu cot %c sang cot %c\n", source, auxiliary1);
    hanoi_4_colums(n - 1, auxiliary2, auxiliary1, source, target);
    printf("Di chuyen dia tu cot %c sang cot %c\n", auxiliary1, target);
    hanoi_4_colums(n - 1, source, auxiliary2, auxiliary1, target);
}

int main() {
    int n = 4;
    hanoi_4_colums(n, 'A', 'B', 'C', 'D');
    return 0;
}