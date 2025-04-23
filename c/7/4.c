/*
4. Дан массив целых чисел, размер массива вводиться с клавиатуры. 
После каждого четного элемента массива вставить случайное число из того же диапазона, что и элементы массива,
затем в полученном массиве удалить все элементы, заканчивающиеся на цифру 1. Вывести промежуточное и результативное состояния массива на экран
*/

#include <stdio.h>
#include <stdlib.h>

int *generateArray(int *arr, int n) {
    int i;
    printf("Generated array: ");
    for (i = 0; i < n; i++) {
        if (i % 2 == 1) {
            arr[i] = -1;
            continue;
        }

        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    return arr;
}

int printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) continue;
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    n *= 2;

    int *arr = (int *)malloc(n * 2 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    arr = generateArray(arr, n);

    for (int i = 0; i < n; i+=2) {
        if (arr[i] % 2 == 0) {
            arr[i + 1] = rand() % 100;
        } else {
            arr[i + 1] = -1;
        }
    }

    printf("After inserting: ");
    printArray(arr, n);

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) continue; 

        if (arr[i] % 10 == 1) {
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
            i--;
        }
    }

    printf("After removing _1: ");
    printArray(arr, n);

    free(arr);
    return 0;
}