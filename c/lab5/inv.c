#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n, i = 0;
    int temp;
    int number[100];
    printf("count: ");
    scanf("%d", &n);


    while (i < n) {
        number[i] = ++i;
    }

    int cnt = 0;
    printf("%d: ", ++cnt);
    for (int i = 0; i < n; i++) printf("%d ", number[i]);
    printf("\n");

    int count = 0;

    int inv[100] = { 0 };

    do {
       

        int permutation[100];
        int available[101];
 
        for (int i = 1; i <= n; i++) {
            available[i] = 1;
        }

       
        for (int i = 0; i < n; i++) {
            int count = 0;
            int num = 1;

            while (count <= inv[i]) {
                if (available[num]) count++;
                if (count <= inv[i]) num++;
            }

            permutation[i] = num;
            available[num] = 0;
        }

        getchar();
        printf("inversion ");
        printf("#%d: ", ++count);
        for (int i = 0; i < n; i++) printf("%d, ", inv[i]);

        printf("\npermutation: ");
        for (int i = 0; i < n; i++) printf("%d, ", permutation[i]);
        printf("\n");


        int found = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (inv[i] < n - 1 - i) {
                inv[i]++;
                
                for (int j = i + 1; j < n; j++) { inv[j] = 0; }
                found = 1;
                
                break;
            }
        }
        if (!found) break;
     

    } while (1);

    return 0;
}