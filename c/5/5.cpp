#include <stdio.h>
#include <random>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n---------\n");

    for (int i = 0; i < n; i++) {
        int temp = arr[i][i];
        arr[i][i] = arr[n - i - 1][i];
        arr[n - i - 1][i] = temp;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}