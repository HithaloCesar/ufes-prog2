#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"

int main(void) {
    tEleicao eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    putchar('\n');

    return EXIT_SUCCESS;
}
