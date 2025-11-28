#include <stdio.h>

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

int main() {
    int n, key;

    printf("n = ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted numbers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("key = ");
    scanf("%d", &key);

    int index = binary_search(arr, n, key);

    if (index != -1)
        printf("Found at index %d\n", index);
    else
        printf("Not found.\n");

    return 0;
}
