#include <stdio.h>
#include <stdlib.h>
#include "esfera_utils.h"

int main(void) {
    float radius;
    scanf("%f", &radius);

    printf("Area: %.2f\n", calcula_area(radius));
    printf("Volume: %.2f\n", calcula_volume(radius));

    return EXIT_SUCCESS;
}
