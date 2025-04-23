//4. Дан двухмерный массив, содержащий NxM целых чисел. В массиве удалить все столбцы, содержащие элементы в состав которых входит цифра  7.

#include <stdio.h>
#include <stdlib.h>

int containsDigit(int num, int digit) {
    while (num > 0) {
        if (num % 10 == digit) {
            return 1;
        }
        num /= 10;
    }
    return 0;
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
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("Original matrix:\n");
    printMatrix(matrix, rows, cols);

    int *validCols = (int *)malloc(cols * sizeof(int));
    int newCols = 0;

    for (int j = 0; j < cols; j++) {
        int hasDigit7 = 0;
        for (int i = 0; i < rows; i++) {
            if (containsDigit(matrix[i][j], 7)) {
                hasDigit7 = 1;
                break;
            }
        }
        if (!hasDigit7) {
            validCols[newCols++] = j;
        }
    }

    int **newMatrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        newMatrix[i] = (int *)malloc(newCols * sizeof(int));
        for (int j = 0; j < newCols; j++) {
            newMatrix[i][j] = matrix[i][validCols[j]];
        }
        free(matrix[i]);
    }
    free(matrix);
    free(validCols);

    printf("Modified matrix:\n");
    printMatrix(newMatrix, rows, newCols);

    for (int i = 0; i < rows; i++) {
        free(newMatrix[i]);
    }
    free(newMatrix);
    return 0;
}
