#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    char even[1000], odd[1000], result[2000];
    int even_idx = 0, odd_idx = 0;

    printf("enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    int len = strlen(input);

    //split into even/odd
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0)
            even[even_idx++] = input[i];
        else
            odd[odd_idx++] = input[i];
    }

    //reverse even array
    for (int i = 0; i < odd_idx / 2; i++) {
        char temp = odd[i];
        odd[i] = odd[odd_idx - 1 - i];
        odd[odd_idx - 1 - i] = temp;
    }

    //concatenate arrays
    int res_idx = 0;
    for (int i = 0; i < even_idx; i++)
        result[res_idx++] = even[i];
    for (int i = 0; i < odd_idx; i++)
        result[res_idx++] = odd[i];

    //reverse
    for (int i = 0; i < res_idx / 2; i++) {
        char temp = result[i];
        result[i] = result[res_idx - 1 - i];
        result[res_idx - 1 - i] = temp;
    }

    result[res_idx] = '\0';

    printf("encrypted string: %s\n", result);

    return 0;
}
