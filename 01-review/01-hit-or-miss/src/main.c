#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float x1, y1, r1; // Target center and radius
    scanf("%f %f %f", &x1, &y1, &r1);
    float x2, y2, r2; // Shot center and radius
    scanf("%f %f %f", &x2, &y2, &r2);

    float d_squared = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    float r_sum_squared = (r1 + r2) * (r1 + r2);

    if (d_squared <= r_sum_squared) {
        printf("ACERTOU\n");
    } else {
        printf("ERROU\n");
    }

    return EXIT_SUCCESS;
}
