#include <stdio.h>
#include <stdlib.h>

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

int binary_search(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid; //return found index

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; //not found
}

void print_array(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, key;

    printf("n = ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    shaker_sort(arr, n);
    print_array(arr, n);

    printf("key = ");
    scanf("%d", &key);

    int index = binary_search(arr, n, key);

    if (index != -1)
        printf("Found at index %d\n", index);
    else
        printf("Not found.\n");

    return 0;
}
