#include <stdio.h>
#include <random>

int areRowsEqual(int arr[3][3]) {
    int prevSum = 0;

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
        if (i == 0) {
            prevSum = sum;
        } else {
            if (sum != prevSum) {
                return 0;
            }
        }
    }

    return 1;
}

int areColsEqual(int arr[3][3]) {
    int prevSum = 0;

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += arr[j][i];
        }
        if (i == 0) {
            prevSum = sum;
        } else {
            if (sum != prevSum) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int arr[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    if ( areRowsEqual(arr) && areColsEqual(arr) ) {
        printf("The array is a logical square\n");
    } else {
        printf("The array is not a logical square\n");
    }
    
}