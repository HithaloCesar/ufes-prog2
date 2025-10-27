#include <stdlib.h>
#include <stdio.h>
#include "data.h"

int main(void) {
    int dia, mes, ano;

    scanf("%d/%d/%d", &dia, &mes, &ano);
    tData data1 = CriaData(dia, mes, ano);

    scanf("%d/%d/%d", &dia, &mes, &ano);
    tData data2 = CriaData(dia, mes, ano);

    if (!VerificaDataValida(data1) || !VerificaDataValida(data2)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        exit(EXIT_FAILURE);
    }

    printf("Primeira data: ");
    ImprimeDataExtenso(data1);

    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    int diff = ComparaData(data1, data2);
    if (diff == 0) {
        printf("As datas sao iguais\n");
    } else {
        printf("A %s data eh mais antiga\n",
            diff < 0 ? "primeira" : "segunda"
        );
    }

    printf("A diferenca em dias entre as datas eh: %02d dias\n",
        CalculaDiferencaDias(data1, data2)
    );

    return EXIT_SUCCESS;
}
