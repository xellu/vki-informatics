#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S3[100];

    char S1[100] = {'A', 'B', 'C', ' ', 'D', 'E', 'F', ' ', 'G', 'H', 'I', '\0'};
    char S2[100] = {'J', 'K', 'L', ' ', 'M', 'N', 'O', '\0'};

    //insert a word from S2 into spaces in S1
    int i = 0;
    int k = 0;
    while (S1[i] != '\0') {
        if (S1[i] == ' ') {
            if (S1[i + 1] == ' ') {
                i++;
            } else {
                S2[k] = S1[i];
                k++;
                i++;
            }
        }

        for (int j = 0; S2[j] != '\0'; j++) {
            S3[j] = S2[strlen(S2) - j - 1];
        }
    }
 
    printf("S1=%s\n", S1);
    printf("S2=%s\n", S2);
    printf("S3=%s\n", S3);
}