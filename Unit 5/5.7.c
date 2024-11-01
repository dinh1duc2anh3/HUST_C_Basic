#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Profile {
    char name[100];
    char dob[11];  // YYYY-MM-DD
};

void heapify(struct Profile arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && strcmp(arr[left].name, arr[largest].name) > 0)
        largest = left;

    if (right < n && strcmp(arr[right].name, arr[largest].name) > 0)
        largest = right;

    if (largest != i) {
        struct Profile temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(struct Profile arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        struct Profile temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void readProfiles(const char *file_path, struct Profile *profiles, int *count) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%s %s", profiles[*count].name, profiles[*count].dob) == 2) {
        (*count)++;
    }

    fclose(file);
}

void writeProfiles(const char *file_path, const struct Profile *profiles, int count) {
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", profiles[i].name, profiles[i].dob);
    }

    fprintf(file, "#\n");
    fclose(file);
}

int main() {
    const char *input_file = "profile-n.txt";
    const char *output_file = "sorted-profile-n.txt";
    struct Profile profiles[100];
    int count;

    readProfiles(input_file, profiles, &count);

    heapSort(profiles, count);

    writeProfiles(output_file, profiles, count);

    return 0;
}
