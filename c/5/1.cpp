#include <stdio.h>
#include <random>

int main() {
    int n, m;
    printf("n = ");
    scanf("%d", &n);

    printf("m = ");
    scanf("%d", &m);
    
    int a[n][m];
    int sum[m];
    int count[m];
    for (int i = 0; i < m; i++) {
        sum[i] = 0;
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 100;

            int is_prime = 1;
            if (a[i][j] < 2) {
                is_prime = 0;
            }
            for (int k = 2; k * k <= a[i][j]; k++) {
                if (a[i][j] % k == 0) {
                    is_prime = 0;
                    break;
                }
            }
            if (is_prime) {
                sum[j] += a[i][j];
                count[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n-------\n");

    for (int i = 0; i < m; i++) {
        printf("%d %d\n", sum[i], count[i]);
    }
}