/*
Дана символьная строка. Слово - последовательность символов между пробелами, не содержащая пробелы внутри себя. Найти самое длинное слово.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char str[100], *word, *longestWord = NULL;
    int maxLength = 0;

    printf("enter a string: ");
    fgets(str, sizeof(str), stdin);

    word = strtok(str, " \n");
    while (word != NULL) {
        int length = strlen(word);
        if (length > maxLength) {
            maxLength = length;
            longestWord = word;
        }
        word = strtok(NULL, " \n");
    }

    if (longestWord != NULL) {
        printf("longest word: %s", longestWord);
    } else {
        printf("a string is empty");
    }
}