/*
Дан массив целых чисел, размер массива вводиться с клавиатуры.  Перед каждым четным элементом массива вставить случайное число из того же диапазона, что и элементы массива,
затем в полученном массиве удалить все элементы, заканчивающиеся на цифру 1. Вывести промежуточное и результативное состояния массива на экран.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, newSize;
    //printf("Введите размер массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Размер массива должен быть положительным.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    printf("Введите элементы массива:\n");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]); 
        //scanf("%d", &arr[i]);
    }
    printf("\n");

    //add a random num before each even integer
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            int randomNum = rand() % 100;
            arr = realloc(arr, (n + 1) * sizeof(int));
            for (j = n; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            arr[i] = randomNum;
            n++;
            i++;
        }
    }

    //this will delete all integers that end with 1
    newSize = n;
    for (i = 0; i < newSize; i++) {
        if (arr[i] % 10 == 1) {
            for (j = i; j < newSize - 1; j++) {
                arr[j] = arr[j + 1];
            }
            newSize--;
            i--;
        }
    }

    printf("\nNew array: ");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}