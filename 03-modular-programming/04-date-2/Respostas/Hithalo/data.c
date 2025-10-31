#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12) {
        return 0;
    }
    return (dia >= 1 && dia <= numeroDiasMes(mes, ano));
}

void imprimeMesExtenso(int mes) {
    switch (mes) {
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
    }
}

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int verificaBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int numeroDiasMes(int mes, int ano) {
    if (mes == 2) {
        if (verificaBissexto(ano)) {
            return 29;
        } else {
            return 28;
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 31;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if (ano1 != ano2) {
        return (ano1 > ano2) ? 1 : -1;
    }
    if (mes1 != mes2) {
        return (mes1 > mes2) ? 1 : -1;
    }
    if (dia1 != dia2) {
        return (dia1 > dia2) ? 1 : -1;
    }
    return 0;
}

int calculaDiasAteMes(int mes, int ano) {
    int day_count = 0;
    for (int i = 1; i < mes; i++) {
        day_count += numeroDiasMes(i, ano);
    }

    return day_count;
}

static void int_swap(int *n1, int *n2) {
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1,
                         int dia2, int mes2, int ano2) {
    int compare_result = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
    if (compare_result > 0) {
        int_swap(&dia1, &dia2);
        int_swap(&mes1, &mes2);
        int_swap(&ano1, &ano2);
    } else if (compare_result == 0) {
        return 0;
    }

    if (ano1 == ano2) {
        int days_to_date_2 = calculaDiasAteMes(mes2, ano2) + dia2;
        int days_to_date_1 = calculaDiasAteMes(mes1, ano1) + dia1;
        return days_to_date_2 - days_to_date_1;
    }

    int days_in_year_date1 = verificaBissexto(ano1) ? 366 : 365;
    int days_to_date_1 = calculaDiasAteMes(mes1, ano1) + dia1;
    int day_count_date1 = days_in_year_date1 - days_to_date_1;

    int day_count_full_years = 0;
    for (int i = ano1 + 1; i < ano2; i++) {
        day_count_full_years += verificaBissexto(i) ? 366 : 365;
    }

    int day_count_date2 = calculaDiasAteMes(mes2, ano2) + dia2;

    return day_count_date1 + day_count_full_years + day_count_date2;
}

void imprimeProximaData(int dia, int mes, int ano) {
    dia++;
    if (dia > numeroDiasMes(mes, ano)) {
        dia = 1;
        mes++;
        if (mes > 12) {
            mes = 1;
            ano++;
        }
    }

    printf("%02d/%02d/%04d", dia, mes, ano);
}
