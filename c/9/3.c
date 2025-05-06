/*
Дано предложение, состоящее из слов, в предложении нет начальных и конечных пробелов.
Словом считается непустая последовательность символов, ограниченная с каждой стороны разделителем или концом строки, в качестве разделителей используются пробелы и запятые.
Предложение вводиться с клавиатуры. Вывести на экран все слова, имеющие минимальное количество символов ‘f’.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char str[100], *word, *minWords[100];

    printf("enter a string: ");
    fgets(str, sizeof(str), stdin);

    word = strtok(str, " ,\n");
    int minCount = 100, count = 0, minWordsCount = 0;

    while (word != NULL) {
        count = 0;
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == 'f') {
                count++;
            }
        }
        if (count < minCount) {
            minCount = count;
            minWordsCount = 0;
            minWords[minWordsCount++] = word;
        } else if (count == minCount) {
            minWords[minWordsCount++] = word;
        }
        word = strtok(NULL, " ,\n");
    }

    if (minCount == 100) {
        printf("no words found\n");
    } else {
        printf("words with minimum 'f' count (%d):\n", minCount);
        for (int i = 0; i < minWordsCount; i++) {
            printf("%s\n", minWords[i]);
        }
    }

}
