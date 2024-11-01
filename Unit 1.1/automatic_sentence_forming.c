#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ARTICLES 5
#define NUM_NOUNS 5
#define NUM_VERBS 5
#define NUM_PREPOSITIONS 5

int getRandom( int min,int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));

    const char *articles[NUM_ARTICLES] ={"the", "a", "one", "some", "any"};
    const char *nouns[NUM_NOUNS] ={"boy", "girl", "dog", "town", "car"};
    const char *verbs[NUM_VERBS] = {"drove", "jumped", "ran", "walked", "skipped"};
    const char *prepositions[NUM_PREPOSITIONS] ={"to", "from", "over", "under", "on"};

    int num_sentences = 10;

    printf("Các câu được tạo:\n");

    for (int i = 0; i < num_sentences; i++) {
        int articleIndex = getRandom(0, NUM_ARTICLES - 1);
        int nounIndex = getRandom(0, NUM_NOUNS - 1);
        int verbIndex = getRandom(0, NUM_VERBS - 1);
        int prepositionIndex = getRandom(0, NUM_PREPOSITIONS - 1);

        printf("%c%s %s %s %s.\n",
               articles[articleIndex][0], 
               articles[articleIndex] + 1, 
               nouns[nounIndex],
               verbs[verbIndex],
               prepositions[prepositionIndex]);
    }

    return 0;
}