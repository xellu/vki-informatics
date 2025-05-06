/*
Дано предложение, состоящее из слов, в предложении нет начальных и конечных пробелов.
Оставить  в нём слова, стоящие на четных местах, а слова, стоящие на нечетных местах, удалить.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char str[100], result[100];

    printf("enter a string: ");
    fgets(str, sizeof(str), stdin);

    char *word = strtok(str, " ,\n");
    int index = 0, wordCount = 0;
    char *words[100];
    while (word != NULL) {
        words[wordCount++] = word;
        word = strtok(NULL, " ,\n");
    }

    for (int i = 0; i < wordCount; i++) {
        if (i % 2 == 0) {
            strcat(result, words[i]);
            strcat(result, " ");
        }
    }

    result[strlen(result) - 1] = '\0'; //remove the trailing space
    printf("modified string: %s\n", result);
}