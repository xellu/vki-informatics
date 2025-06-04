#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "w");

    if (!f1 || !f2) {
        perror("File open error");
        return 1;
    }

    int result = 1;
    int ch;

    while ((ch = fgetc(f1)) != EOF) {
        if (isdigit(ch)) {
            result *= ch - '0'; // Convert char to int
        }
    }

    fprintf(f2, "%d\n", result);

    fclose(f1);
    fclose(f2);

    return 0;
}
