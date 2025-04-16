#include <stdio.h>
#include <random>

int main() {
    int x, y;

    printf("x = ");
    scanf("%d", &x);

    printf("y = ");
    scanf("%d", &y);

    int arr[x][y];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            arr[i][j] = rand() % 100 - 30;
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n---------\n");

    int newArr[x][y];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (arr[i][j] > 0) {
                newArr[i][j] = arr[i][j] + arr[i][0];
            } else {
                newArr[i][j] = arr[i][j] + arr[x - 1][j];
            }
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%4d ", newArr[i][j]);
        }
        printf("\n");
    }
}