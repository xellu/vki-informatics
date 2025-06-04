//REDO IN C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 1000

void main() {
    //generate random letter
    char S1[4] = {'s', 'a', 'r', '\0'};
    printf("S1 = %s\n", S1);
    
    //generate garbage data and write to f1
    FILE *f1 = fopen("f1.txt", "r");

    //read f1 and say whether S1 is in the line    
    for (int i = 0; i < 10; i++) {
        char line[MAX_WORD_LEN];
        if (fgets(line, sizeof(line), f1) != NULL) {
            // Check if S1 is in the line
            int found = 0;
            if (strstr(line, S1) != NULL) {
                found = 1;
            }
            line[strcspn(line, "\n")] = 0;
            printf("%s - %s\n", line, found ? "true" : "false");
        }
    }

}