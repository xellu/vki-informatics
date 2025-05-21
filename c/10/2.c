/*#write anything into f1.txt

f1 = open("f1.txt", "r", encoding="utf-8")
f2 = open("f2.txt", "w", encoding="utf-8")

f2.write(
    "\n".join(list(reversed(f1.read().splitlines())))
)
    */
//C Recode

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "w");
    if (f1 == NULL || f2 == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    char *line = NULL;
    size_t len = 0;
    size_t read;
    char **lines = NULL;
    size_t line_count = 0;
    size_t i;
    while ((read = getline(&line, &len, f1)) != -1) {
        lines = realloc(lines, sizeof(char *) * (line_count + 1));
        lines[line_count] = malloc(read + 1);
        strcpy(lines[line_count], line);
        line_count++;
    }
    free(line);
    for (i = line_count; i > 0; i--) {
        fprintf(f2, "%s\n", lines[i - 1]);
        free(lines[i - 1]);
    }
    free(lines);
    fclose(f1);
    fclose(f2);
    printf("File copied and reversed successfully.\n");
    return;
}