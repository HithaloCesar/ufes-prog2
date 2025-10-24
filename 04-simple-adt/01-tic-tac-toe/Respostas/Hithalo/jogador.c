#include "jogador.h"
#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

tJogador CriaJogador(int idJogador) {
    tJogador player;
    player.id = idJogador;

    return player;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    while (true) {
        printf("Jogador %d\n", jogador.id);

        tJogada play = LeJogada();
        int x = ObtemJogadaX(play);
        int y = ObtemJogadaY(play);

        if (!FoiJogadaBemSucedida(play)) {
            exit(EXIT_FAILURE);
        }

        if (!EhPosicaoValidaTabuleiro(x, y)) {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",
                x, y);
        } else if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        } else {
            tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
            printf("Jogada [%d,%d]!\n", x, y);
            break;
        }
    }

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    int p = jogador.id;

    // Rows
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, p)) {
                break;
            }
            if (j == TAM_TABULEIRO - 1) {
                return 1;
            }
        }
    }

    // Columns
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, p)) {
                break;
            }
            if (j == TAM_TABULEIRO - 1) {
                return 1;
            }
        }
    }

    // Primary diagonal
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, p)) {
            break;
        }
        if (i == TAM_TABULEIRO - 1) {
            return 1;
        }
    }

    // Secondary diagonal
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        int j = TAM_TABULEIRO - 1 - i;
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, p)) {
            break;
        }
        if (i == TAM_TABULEIRO - 1) {
            return 1;
        }
    }

    return 0;
}
