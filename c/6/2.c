/*
Задан двумерный массив А из N строк и М столбцов. Написать функцию для определения в каждой строке массива значения максимального нечётного элемента;
Полученные значения записать в одномерный массив D (в D[0] записать максимальный нечётный элемент 0-ой строки, в D[1] – 1-ой строки и т. д.)
Заполнение матрицы выполнить в отдельной функции. Результаты вывести на экран.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void fillArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 20 + 1;
        }
    }
}

void findMaxOddInRows(int arr[MAX_ROWS][MAX_COLS], int rows, int cols, int maxOdd[]) {
    for (int i = 0; i < rows; i++) {
        maxOdd[i] = -1; //set to -1 to indicate no odd number found
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] % 2 != 0 && arr[i][j] > maxOdd[i]) {
                maxOdd[i] = arr[i][j];
            }
        }
    }
}

void printArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

void print1DArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_ROWS][MAX_COLS];
    int maxOdd[MAX_ROWS];
    int rows = 5; // Number of rows
    int cols = 5; // Number of columns

    fillArray(arr, rows, cols);
    printf("Original Array:\n");
    printArray(arr, rows, cols);

    findMaxOddInRows(arr, rows, cols, maxOdd);
    printf("Max Odd Elements in Each Row:\n");
    print1DArray(maxOdd, rows);

    return 0;
}