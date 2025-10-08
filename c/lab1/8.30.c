#include <stdio.h>

int main() {
    int a, b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    int num, maxDivisors = 0;
    int maxNum = a;  // for part (a) – largest with max divisors
    int minNum = a;  // for part (b) – smallest with max divisors

    for (num = a; num <= b; num++) {
        int count = 0;
        for (int i = 1; i <= num; i++) {
            if (num % i == 0)
                count++;
        }

        if (count > maxDivisors) {
            maxDivisors = count;
            maxNum = num;
            minNum = num;
        } else if (count == maxDivisors) {
            if (num > maxNum)
                maxNum = num; // (a)
            if (num < minNum)
                minNum = num; // (b)
        }
    }

    printf("\nNumber with max divisors: %d\n", maxDivisors);
    printf("Largest number with that many divisors: %d\n", maxNum);
    printf("Smallest number with that many divisors: %d\n", minNum);

    return 0;
}
