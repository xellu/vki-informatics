#include <stdio.h>

void shaker_sort(int arr[], int n) {
    int start = 0, end = n - 1;
    int swapped = 1;

    while (swapped) {
        swapped = 0;

        // Move left -> right
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;

        end--; // Last element is in place
        swapped = 0;

        // Move right -> left
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                int tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
                swapped = 1;
            }
        }
        start++; // First element is in place
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("n = ");
    scanf("%d", &n);

    int arr[n];
    
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    print_array(arr, n);

    shaker_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}
