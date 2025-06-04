#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    int x;
    int y;
} Point2D;

float min_segment_length(Point2D p1, Point2D p2) {
    //calculate distance between two points
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "w");

    if (!f1 || !f2) {
        perror("Error opening file");
        return 1;
    }

    int *values = malloc(sizeof(int) * MAX_POINTS * 4);
    int count = 0;

    while (fscanf(f1, "%d", &values[count]) == 1) {
        count++;
        if (count >= MAX_POINTS * 4) {
            fprintf(stderr, "Too many values in f1.txt (limit: %d)\n", MAX_POINTS * 4);
            break;
        }
    }

    if (count % 4 != 0) {
        fprintf(stderr, "Number of integers must be divisible by 4.\n");
        free(values);
        fclose(f1);
        fclose(f2);
        return 1;
    }

    fprintf(f2, "[\n");

    for (int i = 0; i < count; i += 4) {
        Point2D p1 = { values[i], values[i+1] };
        Point2D p2 = { values[i+2], values[i+3] };
        float msl = min_segment_length(p1, p2);

        printf("p1={x: %d, y: %d} p2={x: %d, y: %d} - Min Length: %f\n", p1.x, p1.y, p2.x, p2.y, msl);

        fprintf(f2,
            "    {\n"
            "        \"p1\": {\"x\": %d, \"y\": %d},\n"
            "        \"p2\": {\"x\": %d, \"y\": %d},\n"
            "        \"min_segment_length\": %f\n"
            "    }%s\n",
            p1.x, p1.y, p2.x, p2.y, msl,
            (i + 4 < count) ? "," : ""
        );
    }

    fprintf(f2, "]\n");

    free(values);
    fclose(f1);
    fclose(f2);

    return 0;
}
