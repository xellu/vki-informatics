#include <stdio.h>

int binary_search(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid; // found, return index

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // not found
}

int main() {
    int n, key;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted numbers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value to search: ");
    scanf("%d", &key);

    int index = binary_search(arr, n, key);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found.\n");

    return 0;
}
