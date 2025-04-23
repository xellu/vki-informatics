//Дан матрица целых чисел, размер матрицы вводиться с клавиатуры. Вставить после столбца с номером К (значение К вводиться с клавиатуры) столбец из  -1 .

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, k;

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

    printf("k=");
    scanf("%d", &k);

    // Insert -1 after column K
    for (int i = 0; i < rows; i++) {
        for (int j = cols; j > k; j--) {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][k] = -1;
    }

    // Print the modified matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}