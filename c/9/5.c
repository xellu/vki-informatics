#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 1000

int is_blank(const char *str) {
    while (*str) {
        if (!isspace(*str)) return 0;
        str++;
    }
    return 1;
}

int main() {
    char input[10000];
    char *words[MAX_WORDS];
    int count = 0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " ");
    while (token != NULL && count < MAX_WORDS) {
        if (!is_blank(token)) {
            words[count] = malloc(strlen(token) + 1);
            strcpy(words[count], token);
            count++;
        }
        token = strtok(NULL, " ");
    }

    for (int j = 1; j < count; j++) {
        for (int i = 1; i < count; i++) {
            if (strlen(words[i]) < strlen(words[i - 1]) ||
                strlen(words[i]) == strlen(words[i - 1])) {
                char *temp = words[i];
                words[i] = words[i - 1];
                words[i - 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s", words[i]);
        if (i < count - 1) printf(" ");
        free(words[i]);
    }
    printf("\n");

    return 0;
}
