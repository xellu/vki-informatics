#include <stdio.h>
#include <string.h>


void build_badchar_table(char *pattern, int m, int badchar[]) {
    for (int i = 0; i < 256; i++)
        badchar[i] = -1;

    for (int i = 0; i < m; i++)
        badchar[(unsigned char)pattern[i]] = i;
}

int boyer_moore(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m == 0) return 0;

    int badchar[256];
    build_badchar_table(pattern, m, badchar);

    int shift = 0;

    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            return shift;  // found match
        } else {
            int bad_index = badchar[(unsigned char)text[shift + j]];
            shift += (j - bad_index > 1) ? j - bad_index : 1;
        }
    }

    return -1; // not found
}

int main() {
    char text[256], pattern[256];

    printf("Text:\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Pattern to query:\n");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    int pos = boyer_moore(text, pattern);

    if (pos != -1)
        printf("Found at position %d\n", pos);
    else
        printf("Not found.\n");

    return 0;
}
