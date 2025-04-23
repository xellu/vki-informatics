//Дан матрица целых чисел, размер матрицы вводиться с клавиатуры. Найти максимальный среди элементов массива, в записи которых есть цифра 3

#include <stdio.h>
#include <stdlib.h>

int **generateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("matrix cols (x): ");
    scanf("%d", &cols);

    printf("matrix rows (y): ");
    scanf("%d", &rows);

    int **matrix = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    matrix = generateMatrix(rows, cols);
    int max = 0;

    printMatrix(matrix, rows, cols);

    //find all numbers that contain digit 3
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int num = matrix[i][j];
            int found = 0;

            while (num > 0) {
                if (num % 10 == 3) {
                    found = 1;
                    break;
                }
                num /= 10;
            }

            if (found && matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    if (max == 0) {
        printf("No elements with digit 3 found.\n");
    } else {
        printf("Max element with digit 3: %d\n", max);
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
}
