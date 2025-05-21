#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "w");
    if (f1 == NULL || f2 == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char ch;
    while ((ch = fgetc(f1)) != EOF) {
        fputc(ch, f2);
    }
    fclose(f1);
    fclose(f2);
}