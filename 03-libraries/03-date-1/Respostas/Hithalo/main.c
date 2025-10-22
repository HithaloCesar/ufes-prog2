#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(void) {
    int day_1, month_1, year_1;
    scanf("%d/%d/%d", &day_1, &month_1, &year_1);
    int day_2, month_2, year_2;
    scanf("%d/%d/%d", &day_2, &month_2, &year_2);

    if (verificaDataValida(day_1, month_1, year_1) == 0
        || verificaDataValida(day_2, month_2, year_2) == 0) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return EXIT_SUCCESS;
    }

    printf("Primeira data: ");
    imprimeDataExtenso(day_1, month_1, year_1);

    printf("Segunda data: ");
    imprimeDataExtenso(day_2, month_2, year_2);

    int compare_result = comparaData(day_1, month_1, year_1,
                                     day_2, month_2, year_2);

    if (compare_result > 0) {
        printf("A segunda data eh mais antiga\n");
    } else if (compare_result < 0) {
        printf("A primeira data eh mais antiga\n");
    } else {
        printf("As datas sao iguais\n");
    }

    printf("A diferenca em dias entre as datas eh: %02d dias\n",
           calculaDiferencaDias(day_1, month_1, year_1,
                                day_2, month_2, year_2));

    return EXIT_SUCCESS;
}
