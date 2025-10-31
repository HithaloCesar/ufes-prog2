#include "data.h"
#include <stdio.h>

tData CriaData(int dia, int mes, int ano) {
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    return data;
}

int VerificaDataValida(tData data) {
    if (data.mes < 1 || data.mes > 12) {
        return 0;
    }

    return data.dia > 0 && data.dia <= NumeroDiasMes(data);
}

void ImprimeMesExtenso(tData data) {
    switch (data.mes) {
        case 1: {
            printf("Janeiro");
            break;
        }
        case 2: {
            printf("Fevereiro");
            break;
        }
        case 3: {
            printf("Marco");
            break;
        }
        case 4: {
            printf("Abril");
            break;
        }
        case 5: {
            printf("Maio");
            break;
        }
        case 6: {
            printf("Junho");
            break;
        }
        case 7: {
            printf("Julho");
            break;
        }
        case 8: {
            printf("Agosto");
            break;
        }
        case 9: {
            printf("Setembro");
            break;
        }
        case 10: {
            printf("Outubro");
            break;
        }
        case 11: {
            printf("Novembro");
            break;
        }
        case 12: {
            printf("Dezembro");
            break;
        }
        default: {
            fprintf(stderr, "ERROR: Invalid month.\n");
            break;
        }
    }
}

void ImprimeDataExtenso(tData data) {
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d", data.ano);
    putchar('\n');
}

int VerificaBissexto(tData data) {
    return (data.ano % 4 == 0 && data.ano % 100 != 0) || data.ano % 400 == 0;
}

int NumeroDiasMes(tData data) {
    if (data.mes < 1 || data.mes > 12) {
        return 0;
    }

    if (data.mes == 2) {
        return VerificaBissexto(data) ? 29 : 28;
    }

    if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) {
        return 30;
    }

    return 31;
}

int ComparaData(tData data1, tData data2) {
    if (data1.ano != data2.ano) {
        return (data1.ano - data2.ano > 0) ? 1 : -1;
    }
    if (data1.mes != data2.mes) {
        return (data1.mes - data2.mes > 0) ? 1 : -1;
    }
    if (data1.dia != data2.dia) {
        return (data1.dia - data2.dia > 0) ? 1 : -1;
    }

    return 0;
}

int CalculaDiasAteMes(tData data) {
    int dias = 0;
    int mesOriginal = data.mes;
    for (data.mes = 1; data.mes < mesOriginal; data.mes++) {
        dias += NumeroDiasMes(data);
    }

    return dias;
}

int CalculaDiferencaDias(tData data1, tData data2) {
    int diff = ComparaData(data1, data2);

    if (diff == 0) {
        return 0;
    }

    if (diff > 0) {
        tData *aux = &data1;
        data1 = data2;
        data2 = *aux;
    }

    int diasAteData1 = CalculaDiasAteMes(data1) + data1.dia;
    int diasAteData2 = CalculaDiasAteMes(data2) + data2.dia;

    if (data1.ano == data2.ano) {
        return diasAteData2 - diasAteData1;
    }

    tData i;
    int diasAnosAteData2 = 0;
    for (i.ano = data1.ano; i.ano < data2.ano; i.ano++) {
        diasAnosAteData2 += VerificaBissexto(i) ? 366 : 365;
    }

    return diasAnosAteData2 - diasAteData1 + diasAteData2;
}
