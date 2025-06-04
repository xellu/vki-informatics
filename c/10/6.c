#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CIRCLES 1000

typedef struct {
    int x;
    int y;
    int r;
} Circle;

void write_circle(FILE *f, Circle c, int is_last) {
    double perimeter = 2 * 3.141 * c.r;
    double area = 3.141 * c.r * c.r;

    fprintf(f,
        "    {\n"
        "        \"x\": %d,\n"
        "        \"y\": %d,\n"
        "        \"radius\": %d,\n"
        "        \"perimeter\": %.6f,\n"
        "        \"area\": %.6f\n"
        "    }%s\n",
        c.x, c.y, c.r,
        perimeter, area,
        is_last ? "" : ","
    );
}

int main() {
    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "w");

    if (!f1 || !f2) {
        perror("Error opening file");
        return 1;
    }

    int values[MAX_CIRCLES * 3];
    int count = 0;

    while (fscanf(f1, "%d", &values[count]) == 1) {
        count++;
        if (count >= MAX_CIRCLES * 3) {
            fprintf(stderr, "Too many values in f1.txt (limit: %d)\n", MAX_CIRCLES * 3);
            break;
        }
    }

    fclose(f1);

    if (count % 3 != 0 || count < 3) {
        fprintf(stderr, "File must contain at least 1 circle (3 numbers) and be divisible by 3.\n");
        fclose(f2);
        return 1;
    }

    int num_circles = count / 3;
    Circle main_circle = { values[0], values[1], values[2] };

    fprintf(f2, "[\n");
    write_circle(f2, main_circle, num_circles == 1);

    int found_any = 0;
    for (int i = 1; i < num_circles; ++i) {
        Circle c = { values[i*3], values[i*3+1], values[i*3+2] };
        double dx = c.x - main_circle.x;
        double dy = c.y - main_circle.y;
        double distance = sqrt(dx * dx + dy * dy);

        if (distance <= c.r + main_circle.r) {
            printf("Circle at x=%d, y=%d intersects with primary circle\n", c.x, c.y);
            if (!found_any) {
                fprintf(f2, ",\n");
            } else {
                fprintf(f2, ",\n");
            }
            write_circle(f2, c, 0);
            found_any = 1;
        }
    }

    fprintf(f2, "]\n");
    fclose(f2);
    return 0;
}
