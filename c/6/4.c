/*
Написать главную программу и функции.
В главной программе осуществляется ввод исходных данных, обращение к функциям и вывод результатов.
С помощью функции упорядочить строки матрицы по возрастанию характеристики. Характеристика строки – количество чисел в строке, у которых сумма делителей равна 7.
Вычисление суммы делителей осуществляется в функции. Размеры матрицы вводятся с клавиатуры, матрица заполняется целыми числами случайным образом.

Заполнение и вывод матрицы осуществить функциями.
Все входные данные и результаты передаются в функции через список параметров, глобальные переменные в них использовать нельзя.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_VALUE 20
#define MIN_VALUE 1

void fillArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }
}
void printArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

int sumOfDivisors(int num)
{
    int sum = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

void filterNonZeroCharacteristicRows(int arr[MAX_ROWS][MAX_COLS], int *rows, int cols) {
    int newRow = 0;
    for (int i = 0; i < *rows; i++)
    {
        int count = 0;
        for (int j = 0; j < cols; j++)
        {
            if (sumOfDivisors(arr[i][j]) == 7)
                count++;
        }
        if (count > 0)
        {
            if (newRow != i)
            {
                for (int j = 0; j < cols; j++)
                {
                    arr[newRow][j] = arr[i][j];
                }
            }
            newRow++;
        }
    }
    *rows = newRow;

    printf("Filtered Array:\n");
    printArray(arr, newRow, cols);
}


void sort(int arr[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < rows - i - 1; j++)
        {
            int count1 = 0, count2 = 0;
            for (int k = 0; k < cols; k++)
            {
                if (sumOfDivisors(arr[j][k]) == 7)
                    count1++;
                if (sumOfDivisors(arr[j + 1][k]) == 7)
                    count2++;
            }
            if (count1 > count2)
            {
                for (int k = 0; k < cols; k++)
                {
                    int temp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp;
                }
            }
        }
    }

    printf("Sorted Array:\n");
    printArray(arr, rows, cols);
    filterNonZeroCharacteristicRows(arr, &rows, cols);
}



int main()
{
    int arr[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS)
    {
        printf("Invalid dimensions!\n");
        return 1;
    }

    fillArray(arr, rows, cols);
    printf("Original Array:\n");
    printArray(arr, rows, cols);

    sort(arr, rows, cols);

    return 0;
}
