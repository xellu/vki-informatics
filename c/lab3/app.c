#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int charToValue(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'F')
        return 10 + (c - 'A');
    else if (c >= 'a' && c <= 'f')
        return 10 + (c - 'a');
    return -1; // invalid
}

char valueToChar(int v) {
    if (v < 10)
        return '0' + v;
    else
        return 'A' + (v - 10);
}

//convert number w fractions to decimal
double toDecimalFloat(const char *num, int fromBase) {
    double result = 0.0;
    const char *dot = strchr(num, '.');
    int len = dot ? (dot - num) : strlen(num);

    //cely cislo
    for (int i = 0; i < len; i++) {
        int value = charToValue(num[i]);
        if (value >= fromBase || value < 0) {
            printf("Invalid digit '%c' for base %d\n", num[i], fromBase);
            return -1;
        }
        result = result * fromBase + value;
    }

    //desetinny cislo
    if (dot) {
        double frac = 0.0;
        double divisor = fromBase;
        for (int i = len + 1; num[i] != '\0'; i++) {
            int value = charToValue(num[i]);
            if (value >= fromBase || value < 0) {
                printf("invalid digit '%c' for base %d\n", num[i], fromBase);
                return -1;
            }
            frac += value / divisor;
            divisor *= fromBase;
        }
        result += frac;
    }

    return result;
}

//decimal conversion w fractions
void fromDecimalFloat(double num, int toBase, char *result) {
    char intPart[64], fracPart[64];
    long long integer = (long long)num;
    double fraction = num - integer;

    //integer
    if (integer == 0)
        strcpy(intPart, "0");
    else {
        char buffer[64];
        int i = 0;
        while (integer > 0) {
            buffer[i++] = valueToChar(integer % toBase);
            integer /= toBase;
        }
        for (int j = 0; j < i; j++)
            intPart[j] = buffer[i - j - 1];
        intPart[i] = '\0';
    }

    //fraction
    int precision = 15; //num digits after decimal point
    int i = 0;
    while (fraction > 0 && i < precision) {
        fraction *= toBase;
        int digit = (int)fraction;
        fracPart[i++] = valueToChar(digit);
        fraction -= digit;
    }
    fracPart[i] = '\0';

    // Combine
    if (i > 0)
        sprintf(result, "%s.%s", intPart, fracPart);
    else
        strcpy(result, intPart);
}

int main() {
    char num[64];
    int fromBase, toBase;
    printf("number: ");
    scanf("%s", num);
    printf("base to convert FROM: ");
    scanf("%d", &fromBase);
    printf("base to convert TO: ");
    scanf("%d", &toBase);

    double decimal = toDecimalFloat(num, fromBase);
    if (decimal < 0) return 1; //error

    char result[128];
    fromDecimalFloat(decimal, toBase, result);

    printf("%s (b%d) = %s (b%d)\n", num, fromBase, result, toBase);

    return 0;
}
