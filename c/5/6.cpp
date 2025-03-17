#include <stdio.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    int arr[n][n];
    int num = 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = num++;
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                arr[i][j] = num++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}