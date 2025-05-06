/*
Дана строка s. Подсчитать количество вхождений буквосочетаний «milk»  в строку s и заменить все вхождения буквосочетания «milk» на «million».
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char str[100], *ptr, *oldStr = "milk", *newStr = "million";
    int count = 0, oldStrLen = strlen(oldStr), newStrLen = strlen(newStr);

    printf("enter a string: ");
    fgets(str, sizeof(str), stdin);

    ptr = strstr(str, oldStr);
    while (ptr != NULL) {
        count++;
        ptr = strstr(ptr + oldStrLen, oldStr);
    }

    printf("number of occurrences: %d\n", count);

    // Replace all occurrences of "milk" with "million"
    char *result = malloc(strlen(str) + (newStrLen - oldStrLen) * count + 1);
    char *pos = str;
    char *resPos = result;

    while ((ptr = strstr(pos, oldStr)) != NULL) {
        strncpy(resPos, pos, ptr - pos);
        resPos += ptr - pos;
        strcpy(resPos, newStr);
        resPos += newStrLen;
        pos = ptr + oldStrLen;
    }
    strcpy(resPos, pos);

    printf("modified string: %s", result);

    free(result);
}