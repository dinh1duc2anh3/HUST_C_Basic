#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Profile {
    char name[100];
    char birthdate[11];
};

int compareDates(const char *date1, const char *date2) {
    return strcmp(date1, date2);
}

int compareNames(const char *name1, const char *name2) {
    return strcmp(name1, name2);
}

int compareProfiles(const void *profile1, const void *profile2) {
    struct Profile *p1 = (struct Profile *)profile1;
    struct Profile *p2 = (struct Profile *)profile2;

    int nameComparison = compareNames(p1->name, p2->name);
    if (nameComparison == 0) {
        return compareDates(p1->birthdate, p2->birthdate);
    }

    return nameComparison;
}

void sortProfiles(struct Profile *profiles, int n) {
    qsort(profiles, n, sizeof(struct Profile), compareProfiles);
}

void readProfiles(const char *filename, struct Profile *profiles, int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *n = 0;
    while (fscanf(file, "%s %s", profiles[*n].name, profiles[*n].birthdate) != EOF) {
        (*n)++;
    }

    fclose(file);
}

void writeProfiles(const char *filename, const struct Profile *profiles, int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %s\n", profiles[i].name, profiles[i].birthdate);
    }

    fprintf(file, "#\n");
    fclose(file);
}

int main() {
    const char *inputFilename = "profile-n.txt";
    const char *outputFilename = "sorted-profile-n.txt";

    struct Profile profiles[100];
    int n;

    readProfiles(inputFilename, profiles, &n);
    sortProfiles(profiles, n);
    writeProfiles(outputFilename, profiles, n);

    return 0;
}
