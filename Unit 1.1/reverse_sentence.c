#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Vui lòng nhập câu từ đối số dòng lệnh.\n");
        return 1;
    }

    char reversedSentence[1000] = "";

    for (int i = argc - 1; i >= 1; i--) {
        strcat(reversedSentence, argv[i]);
        strcat(reversedSentence, " ");
    }


    printf("%s\n", reversedSentence);

    return 0;
}
