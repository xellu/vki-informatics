#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int values[] = {64, 32, 16, 8, 4, 2, 1};
    int size = 7;

    for (int x = n; x <= n + 10; x++) {
        int amount = x;
        int count[7] = {0}; // how many of each note

        for (int i = 0; i < size; i++) {
            count[i] = amount / values[i];
            amount %= values[i];
        }

        // Count total number of notes
        int total = 0;
        for (int i = 0; i < size; i++)
            total += count[i];

        printf("\nn = %d\n", x);
        printf("Total banknotes: %d\n", total);
        printf("Breakdown: ");
        for (int i = 0; i < size; i++) {
            if (count[i] > 0)
                printf("%d×%d ", count[i], values[i]);
        }
        printf("\n");
    }

    return 0;
}
