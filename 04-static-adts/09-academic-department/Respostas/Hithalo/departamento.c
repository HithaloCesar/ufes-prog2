#include "departamento.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

static int qsortComparaDeptMedia(const void *d1, const void *d2);

tDepartamento criaDepartamento(
    char* c1,
    char* c2,
    char* c3,
    char* nome,
    int m1,
    int m2,
    int m3,
    char* diretor
) {
    tDepartamento dept;
    strcpy(dept.c1, c1);
    strcpy(dept.c2, c2);
    strcpy(dept.c3, c3);
    strcpy(dept.nome, nome);
    strcpy(dept.diretor, diretor);
    dept.m1 = m1;
    dept.m2 = m2;
    dept.m3 = m3;

    return dept;
}

void imprimeAtributosDepartamento (tDepartamento depto) {
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2f\n", calculaMediaGeralDepartamento(depto));
    printf("desvio padrao => %.2f\n", calculaDesvioPadraoDepartamento(depto));
    putchar('\n');
}

int validaMediaDepartamento (int media) {
    return media >= 0 && media <= 10;
}

double calculaDesvioPadraoDepartamento(tDepartamento depto) {
    double mediaGeral = calculaMediaGeralDepartamento(depto);
    double somatorio = 0;
    somatorio += (depto.m1 - mediaGeral) * (depto.m1 - mediaGeral);
    somatorio += (depto.m2 - mediaGeral) * (depto.m2 - mediaGeral);
    somatorio += (depto.m3 - mediaGeral) * (depto.m3 - mediaGeral);

    return sqrt(somatorio / 3);
}

double calculaMediaGeralDepartamento(tDepartamento depto) {
    return (depto.m1 + depto.m2 + depto.m3) / 3.0;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho) {
    qsort(d, tamanho, sizeof(tDepartamento), qsortComparaDeptMedia);
}

static int qsortComparaDeptMedia(const void *d1, const void *d2) {
    double mediaGeral1 = calculaMediaGeralDepartamento(*(tDepartamento*)d1);
    double mediaGeral2 = calculaMediaGeralDepartamento(*(tDepartamento*)d2);

    if (mediaGeral1 > mediaGeral2) {
        return -1;
    }

    if (mediaGeral1 < mediaGeral2) {
        return 1;
    }

    return 0;
}
