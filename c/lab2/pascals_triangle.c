#include <stdio.h>

long long fact(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

void pascal_formula(int rows) { //pomoci formuly: n! / (k! * (n-k)!)
    printf("Pascal's triangle (using factorial formula):\n");
    for (int n = 0; n < rows; n++) {
        for (int s = 0; s < rows - n; s++)
            printf(" ");
        for (int k = 0; k <= n; k++) {
            long long value = fact(n) / (fact(k) * fact(n - k));
            printf("%lld ", value);
        }
        printf("\n");
    }
}

void pascal_iterative(int rows) { //pomoci iterace
    printf("\nPascal's triangle (using iterative addition):\n");
    int triangle[50][50] = {0};

    for (int n = 0; n < rows; n++) {
        triangle[n][0] = 1;
        triangle[n][n] = 1;

        for (int k = 1; k < n; k++)
            triangle[n][k] = triangle[n - 1][k - 1] + triangle[n - 1][k];

        for (int s = 0; s < rows - n; s++)
            printf(" ");
        for (int k = 0; k <= n; k++)
            printf("%d ", triangle[n][k]);
        printf("\n");
    }
}

int main() {
    int rows;
    printf("iterations: ");
    scanf("%d", &rows);

    pascal_formula(rows);
    pascal_iterative(rows);

    return 0;
}
