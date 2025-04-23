//Дан двухмерный массив, содержащий NxM целых чисел. В массиве удалить все строки, содержащие хотя бы одно простое число.

#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
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

    for (int i = 0; i < rows; i++) {
        int hasPrime = 0;
        for (int j = 0; j < cols; j++) {
            if (isPrime(matrix[i][j])) {
                hasPrime = 1;
                break;
            }
        }
        if (hasPrime) {
            free(matrix[i]);
            matrix[i] = NULL; //mark the row for deletion
        }
    }

    int newRowCount = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i] != NULL) {
            newRowCount++;
        }
    }
    
    int **newMatrix = (int **)malloc(newRowCount * sizeof(int *));
    int newIndex = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i] != NULL) {
            newMatrix[newIndex] = matrix[i];
            newIndex++;
        } else {
            free(matrix[i]);
        }
    }
    
    free(matrix);
    matrix = newMatrix;
    rows = newRowCount;

    printf("Modified matrix:\n");
    printMatrix(matrix, rows, cols);

}