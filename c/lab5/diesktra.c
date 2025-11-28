#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Dijkstra's next permutation (returns 0 if no more permutations)
int next_permutation(int *a, int n) {
    int i = n - 2;

    // 1. Find i such that a[i] < a[i+1]
    while (i >= 0 && a[i] >= a[i + 1])
        i--;

    if (i < 0)
        return 0; // last permutation reached

    // 2. Find j > i such that a[j] > a[i]
    int j = n - 1;
    while (a[j] <= a[i])
        j--;

    // 3. Swap a[i], a[j]
    swap(&a[i], &a[j]);

    // 4. Reverse tail (i+1 ... n-1)
    int left = i + 1, right = n - 1;
    while (left < right)
        swap(&a[left++], &a[right--]);

    return 1;
}

void print_array(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;

    printf("n = ");
    scanf("%d", &n);

    int a[n];
    
    for (int i = 0; i < n; i++)
        a[i] = rand() % 10;

    // Print first permutation
    print_array(a, n);
    getchar(); // wait for key

    // Generate next permutations
    while (next_permutation(a, n)) {
        print_array(a, n);
        getchar(); // wait for key
    }

    return 0;
}
