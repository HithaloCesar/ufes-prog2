#include "data.h"
#include <stdio.h>

Data criaData(int dia, int mes, int ano) {
    Data data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    return data;
}

Data lerData() {
    int dia, mes, ano;
    scanf("%d/%d/%d\n", &dia, &mes, &ano);

    return criaData(dia, mes, ano);
}

int diferencaAnoData(Data inicial, Data atual) {
    int anosCompletos = atual.ano - inicial.ano;

    if (atual.mes < inicial.mes
        || (atual.mes == inicial.mes && atual.dia < inicial.dia)) {
        anosCompletos--;
    }

    return anosCompletos;
}

void imprimeData(Data d) {
    printf("%02d/%02d/%d", d.dia, d.mes, d.ano);
}
