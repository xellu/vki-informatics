/*
Дан двумерный массив А целых чисел, лежащих в диапазоне [1-20], состоящий из N строк и N столбцов.
Написать функцию для вычисления в массиве суммы элементов над главной диагональю и суммы элементов под главной диагональю.
Элементы главной диагонали занести в одномерный массив. Заполнение матрицы выполнить в отдельной функции. Результаты вывести на экран.
*/

#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void diagonalSums(int arr[][10], int N, int *above, int *below, int diag[]) {
    *above = 0;
    *below = 0;

    for (int i = 0; i < N; i++) {
        diag[i] = arr[i][i]; // Main diagonal
        for (int j = 0; j < N; j++) {
            if (j > i) {
                *above += arr[i][j];
            } else if (j < i) {
                *below += arr[i][j];
            }
        }
    }
}

int main() {
    int N = 10;
    int arr[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = rand() % 20 + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        printArr(arr[i], N);
    }

    int above, below;
    int diag[N];

    diagonalSums(arr, N, &above, &below, diag);
    printf("Sum above diagonal: %d\n", above);

    printf("Sum below diagonal: %d\n", below);
    printf("Main diagonal: ");
    printArr(diag, N);
    return 0;
}