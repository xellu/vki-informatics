#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000

int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "w");

    if (!f1 || !f2) {
        perror("File open error");
        return 1;
    }

    int data[MAX_LINES];
    int count = 0;

    while (fscanf(f1, "%d", &data[count]) == 1 && count < MAX_LINES) {
        count++;
    }

    fclose(f1);

    qsort(data, count, sizeof(int), compare_ints);

    for (int i = 0; i < count; i++) {
        fprintf(f2, "%d\n", data[i]);
    }

    fclose(f2);
    return 0;
}
