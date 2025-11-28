#include <stdio.h>

// Binary search to find insert position
int binary_search(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (item == arr[mid])
            return mid + 1;

        if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Binary insertion sort
void binary_insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int selected = arr[i];
        int loc = binary_search(arr, selected, 0, i - 1);

        int j = i - 1;
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
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
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    binary_insertion_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}
