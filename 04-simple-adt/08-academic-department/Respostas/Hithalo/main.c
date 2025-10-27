#include <stdlib.h>
#include <stdio.h>
#include "departamento.h"

#define MAX_QTD_DEPT 16

int main(void) {
    int qtdDept;
    scanf("%d", &qtdDept);

    tDepartamento deptList[MAX_QTD_DEPT];
    for (int i = 0; i < qtdDept; i++) {
        char nome[STRING_MAX];
        char c1[STRING_MAX];
        char c2[STRING_MAX];
        char c3[STRING_MAX];
        char diretor[STRING_MAX];
        int m1, m2, m3;

        scanf(" %[^\n]", nome);
        scanf(" %[^\n]", diretor);
        scanf(" %[^\n]", c1);
        scanf(" %[^\n]", c2);
        scanf(" %[^\n]", c3);
        scanf("%d %d %d", &m1, &m2, &m3);

        deptList[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }

    ordenaPorMediaDepartamentos(deptList, qtdDept);
    for (int i = 0; i < qtdDept; i++) {
        imprimeAtributosDepartamento(deptList[i]);
    }

    return EXIT_SUCCESS;
}
