#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "locadora.h"

#define STDIN_BUFFER_SIZE 16

int main(void) {
    tLocadora locadora = criarLocadora();

    char operation[STDIN_BUFFER_SIZE];
    while (scanf(" %s ", operation) == 1) {
        if (!strcmp(operation, "Cadastrar")) {
            locadora = lerCadastroLocadora(locadora);
        } else if (!strcmp(operation, "Alugar")) {
            locadora = lerAluguelLocadora(locadora);
        } else if (!strcmp(operation, "Devolver")) {
            locadora = lerDevolucaoLocadora(locadora);
        } else if (!strcmp(operation, "Estoque")) {
            locadora = ordenarFilmesLocadora(locadora);
            putchar('\n');
            consultarEstoqueLocadora(locadora);
        }
    }

    consultarLucroLocadora(locadora);

    return EXIT_SUCCESS;
}
