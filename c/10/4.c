//Дан файл f содержащий целые числа. Записать в файл f1 компоненты
//исходного файла, имеющие ровно 3 делителя.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate() {
    FILE *f1 = fopen("f1.txt", "w");
    if (f1 == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            fputc('0' + rand() % 10, f1); // Random digit
        }
        fputc('\n', f1);
    }
    fclose(f1);
}

int counter(int num) {
    int count = 0;
    num = abs(num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    return count;
}

void lookup() {
    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "w");

    char line[100];
    while (fgets(line, sizeof(line), f1)) {
        int num = atoi(line);
        int count = counter(num);
        if (count == 3) {
            fprintf(f2, "%s", line);
        }

        line[strcspn(line, "\n")] = 0;
        printf("%s - %d - %s\n", line, count, count == 3 ? "true" : "false");
    }

    fclose(f1);
    fclose(f2);
}

void main() {
    generate();
    lookup();
}