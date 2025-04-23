/*
Дан массив целых чисел, размер массива вводиться с клавиатуры.
Посчитать сумму нечетных элементов расположенных после минимального элемента или первого вхождения минимального элемента,
если их несколько. Вывести  исходное и результативное состояния массива на экран.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, minIndex = 0, sum = 0;
    printf("Введите размер массива: ");
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
        scanf("%d", &arr[i]);
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    for (i = minIndex + 1; i < n; i++) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
        }
    }

    printf("Исходный массив: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nСумма нечетных элементов после минимального элемента: %d\n", sum);

    free(arr);
    return 0;
}