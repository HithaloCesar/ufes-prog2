#include <stdlib.h>
#include <stdio.h>
#include "empresa.h"

#define MAX_QTD_EMPRESAS 8

int main(void) {
    int qtdEmpresas;
    scanf("%d", &qtdEmpresas);

    tEmpresa empresas[MAX_QTD_EMPRESAS];
    for (int i = 0; i < qtdEmpresas; i++) {
        empresas[i] = leEmpresa();
    }

    for (int i = 0; i < qtdEmpresas; i++) {
        imprimeEmpresa(empresas[i]);

        if (i < qtdEmpresas - 1) {
            putchar('\n');
        }
    }

    return EXIT_SUCCESS;
}
