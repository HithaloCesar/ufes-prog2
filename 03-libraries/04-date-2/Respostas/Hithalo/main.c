#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(void) {
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);

    if (!verificaDataValida(day, month, year)) {
        printf("A data informada eh invalida\n");
        return EXIT_FAILURE;
    }

    printf("Data informada: ");
    imprimeDataExtenso(day, month, year);

    printf("O ano informado%seh bissexto\n",
           verificaBissexto(year) ? " " : " nao ");

    printf("O mes informado possui %d dias\n", numeroDiasMes(month, year));

    printf("A data seguinte eh: ");
    imprimeProximaData(day, month, year);
    putchar('\n');

    return EXIT_SUCCESS;
}
