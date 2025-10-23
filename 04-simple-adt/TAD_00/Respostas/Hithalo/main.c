#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main(void) {
    float x, y;

    scanf("%f %f", &x, &y);
    Ponto p1 = pto_cria(x, y);

    scanf("%f %f", &x, &y);
    Ponto p2 = pto_cria(x, y);

    printf("%g\n", pto_distancia(p1, p2));

    return EXIT_SUCCESS;
}
