#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Convert a single digit character to its numeric value
int charToValue(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'F')
        return 10 + (c - 'A');
    else if (c >= 'a' && c <= 'f')
        return 10 + (c - 'a');
    return -1; // invalid
}

// Convert a numeric value (0–15) to character
char valueToChar(int v) {
    if (v < 10)
        return '0' + v;
    else
        return 'A' + (v - 10);
}

// Convert number from base `fromBase` to decimal
long long toDecimal(const char *num, int fromBase) {
    long long result = 0;
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        int value = charToValue(num[i]);
        if (value >= fromBase || value < 0) {
            printf("Invalid digit '%c' for base %d\n", num[i], fromBase);
            return -1;
        }
        result = result * fromBase + value;
    }
    return result;
}

// Convert decimal number to base `toBase`
void fromDecimal(long long num, int toBase, char *result) {
    char buffer[64];
    int i = 0;

    if (num == 0) {
        strcpy(result, "0");
        return;
    }

    while (num > 0) {
        buffer[i++] = valueToChar(num % toBase);
        num /= toBase;
    }

    // reverse the result
    for (int j = 0; j < i; j++)
        result[j] = buffer[i - j - 1];
    result[i] = '\0';
}

int main() {
    char num[64];
    int fromBase, toBase;
    printf("Enter number: ");
    scanf("%s", num);
    printf("Enter base to convert FROM: ");
    scanf("%d", &fromBase);
    printf("Enter base to convert TO: ");
    scanf("%d", &toBase);

    long long decimal = toDecimal(num, fromBase);
    if (decimal == -1) return 1; // error

    char result[64];
    fromDecimal(decimal, toBase, result);

    printf("\nNumber %s (base %d) = %s (base %d)\n", num, fromBase, result, toBase);

    return 0;
}
