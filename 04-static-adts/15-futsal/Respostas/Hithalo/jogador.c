#include "jogador.h"
#include <stdio.h>
#include <string.h>

void tJogador_copiaNome(tJogador j, char dst[]) {
    strcpy(dst, j.nome);
}

int tJogador_getIdEquipe(tJogador j) {
    return j.idEquipe;
}

int tJogador_getIdUnico(tJogador j) {
    return j.idUnico;
}

tJogador lerJogador() {
    tJogador jogador;
    scanf("%d", &jogador.idUnico);
    scanf("%d", &jogador.idEquipe);
    scanf(" %[^\n]", jogador.nome);

    return jogador;
}
