#include <stdio.h>
#include <string.h>

#define MAX_PROFILES 100

struct Profile {
    char name[100];
    char dob[11]; // Assuming the date of birth is in the format YYYY-MM-DD
};

void merge(struct Profile arr[], int l, int m, int r);
void mergeSort(struct Profile arr[], int l, int r);
int compareProfiles(struct Profile profile1, struct Profile profile2);
void readProfiles(char filename[], struct Profile profiles[]);
void writeProfiles(char filename[], struct Profile profiles[]);

int main() {
    char inputFilename[] = "Profile-5.txt";
    char outputFilename[] = "Sorted-Profile-5.txt";
    
    struct Profile profiles[MAX_PROFILES];
    readProfiles(inputFilename, profiles);

    int n = 0;
    while (strlen(profiles[n].name) > 0) {
        n++;
    }

    mergeSort(profiles, 0, n - 1);
    
    writeProfiles(outputFilename, profiles);

    printf("Sorted profiles have been written to %s\n", outputFilename);

    return 0;
}

void merge(struct Profile arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    struct Profile L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (compareProfiles(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Profile arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int compareProfiles(struct Profile profile1, struct Profile profile2) {
    int cmp = strcmp(profile1.name, profile2.name);
    
    if (cmp != 0) {
        return cmp;
    }

    return strcmp(profile1.dob, profile2.dob);
}

void readProfiles(char filename[], struct Profile profiles[]) {
    FILE *file = fopen(filename, "r");
    int i = 0;

    while (fscanf(file, "%[^\n]\n%[^\n]\n", profiles[i].name, profiles[i].dob) != EOF) {
        i++;
    }

    fclose(file);
}

void writeProfiles(char filename[], struct Profile profiles[]) {
    FILE *file = fopen(filename, "w");
    int i = 0;

    while (strlen(profiles[i].name) > 0) {
        fprintf(file, "%s\n%s\n", profiles[i].name, profiles[i].dob);
        i++;
    }

    fprintf(file, "#\n");
    fclose(file);
}
