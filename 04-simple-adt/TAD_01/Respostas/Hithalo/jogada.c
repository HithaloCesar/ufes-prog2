#include "jogada.h"
#include <stdio.h>

tJogada LeJogada() {
    tJogada play = {0};

    printf("Digite uma posicao (x e y):\n");
    if (scanf("%d %d", &play.x, &play.y) == 2) {
        play.sucesso = 1;
    }

    return play;
}

int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada) {
    return jogada.sucesso;
}
