/*
Дан массив целых чисел, размер массива вводиться с клавиатуры. 
Первый элемент файла – количество этих чисел, следующие элементы  - последовательность чисел (напр. 4 1 67 2 23).
Заменить в данной последовательности все заканчивающиеся на четную цифру элементы на максимальный элемент последовательности.
Вывести  исходное и результативное состояния массива на экран.
*/


#include <stdio.h>
#include <stdlib.h>

int *generateArray(int *arr, int n) {
    int i;
    printf("Generated array: ");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    return arr;
}

int getMax(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Max element: %d\n", max);
    return max;
}

int printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int *transformArray(int *arr, int n, int max) {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 10 % 2 == 0) {
            arr[i] = max;
        }
    }
    return arr;
}

int main() {
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    n++;

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    arr = generateArray(arr, n);
    int max = getMax(arr, n);

    printArray(arr, n);

    arr[0] = n-1;

    arr = transformArray(arr, n, max);

    printArray(arr, n);

}