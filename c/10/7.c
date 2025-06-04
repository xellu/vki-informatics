#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 200
#define MAX_LEN 100

void to_lower_str(char *dest, const char *src) {
    while (*src) {
        *dest++ = tolower(*src++);
    }
    *dest = '\0';
}

int main() {
    char *countries[MAX_LINES];
    char *capitals[MAX_LINES];
    int total = 0;

    FILE *fc = fopen("gos.txt", "r");
    FILE *fcap = fopen("capital.txt", "r");

    if (!fc || !fcap) {
        perror("Error opening file");
        return 1;
    }

    // Read gos.txt
    char buf[MAX_LEN];
    while (fgets(buf, sizeof(buf), fc)) {
        buf[strcspn(buf, "\n")] = 0; // Remove newline
        countries[total] = strdup(buf);
        total++;
        if (total >= MAX_LINES) break;
    }
    fclose(fc);

    // Read capital.txt
    for (int i = 0; i < total; ++i) {
        if (fgets(buf, sizeof(buf), fcap)) {
            buf[strcspn(buf, "\n")] = 0;
            capitals[i] = strdup(buf);
        }
    }
    fclose(fcap);

    while (1) {
        printf("\nlookup using:\n1 - country\n2 - capital city\n> ");
        char mode[3];
        fgets(mode, sizeof(mode), stdin);

        printf("query> ");
        char input[MAX_LEN], lowered_input[MAX_LEN];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        to_lower_str(lowered_input, input);

        int found = 0;

        if (mode[0] == '1') {
            for (int i = 0; i < total; ++i) {
                char *line = countries[i];
                char *name = strtok(line, ";");
                while (name) {
                    char lowered_name[MAX_LEN];
                    to_lower_str(lowered_name, name);
                    if (strcmp(lowered_input, lowered_name) == 0) {
                        printf("The capital of %s is '%s'\n", name, capitals[i]);
                        found = 1;
                        break;
                    }
                    name = strtok(NULL, ";");
                }
                if (found) break;
            }
        } else {
            for (int i = 0; i < total; ++i) {
                char lowered_capital[MAX_LEN];
                to_lower_str(lowered_capital, capitals[i]);
                if (strcmp(lowered_input, lowered_capital) == 0) {
                    char *main_country = strtok(countries[i], ";");
                    printf("%s is the capital city of '%s'\n", capitals[i], main_country);
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            printf("No match found.\n");
        }
    }

    // Cleanup (unreachable here due to infinite loop)
    for (int i = 0; i < total; ++i) {
        free(countries[i]);
        free(capitals[i]);
    }

    return 0;
}
