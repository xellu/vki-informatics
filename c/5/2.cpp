//"Find and display the indices of the last k negative elements of each column (if there are none, display the corresponding message)."

#include <stdio.h>
#include <random>

int main() {
    int x, y, k;

    printf("x = ");
    scanf("%d", &x);

    printf("y = ");
    scanf("%d", &y);

    printf("k = ");
    scanf("%d", &k);

    int arr[x][y];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            arr[i][j] = rand() % 100 - 30;
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n---------\n");
    printf("ROW | COL");
    printf("\n---------\n");

    for (int i = 0; i < y; i++) {
        int count = 0;
        for (int j = x - 1; j >= 0; j--) {
            if (arr[j][i] < 0) {
                printf("%d   | %d\n", j, i);
                count++;
            }
            if (count == k) {
                break;
            }
        }
        if (count == 0) {
            printf("No negative elements in column %d\n", i);
        }
    }

    return 0;   
}