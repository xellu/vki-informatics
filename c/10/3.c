//REDO IN C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 1000

void main() {
    //generate random letter
    char S1 = 'a' + rand() % 26; // Random lowercase letter from 'a' to 'z'
    printf("S1 = %c\n", S1);
    
    //generate garbage data and write to f1
    FILE *f1 = fopen("f1.txt", "w");
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fputc('a' + rand() % 26, f1); // Random lowercase letter
        }
        fputc('\n', f1);
    }
    fclose(f1);

    //read f1 and say whether S1 is in the line
    f1 = fopen("f1.txt", "r");
    
    for (int i = 0; i < 10; i++) {
        char line[MAX_WORD_LEN];
        if (fgets(line, sizeof(line), f1) != NULL) {
            // Check if S1 is in the line
            int found = 0;
            for (int j = 0; j < strlen(line); j++) {
                if (line[j] == S1) {
                    found = 1;
                    break;
                }
            }
            line[strcspn(line, "\n")] = 0;
            printf("%s - %s\n", line, found ? "true" : "false");
        }
    }

}