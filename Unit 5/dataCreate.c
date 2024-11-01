#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, M;
    scanf("%d %d %d", &n, &m, &M);

    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    fprintf(file, "%d\n", n);

    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        int random_number = rand() % (M - m + 1) + m;
        fprintf(file, "%d", random_number);

        if (i < n - 1) {
            fprintf(file, " ");
        } else {
            fprintf(file, "\n");
        }
    }

    fclose(file);

    return 0;
}


