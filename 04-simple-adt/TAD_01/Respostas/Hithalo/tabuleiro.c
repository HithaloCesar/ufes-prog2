#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro() {
    tTabuleiro board = {0};

    board.peca1 = PECA_1;
    board.peca2 = PECA_2;

    return board;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro,
                                 int peca, int x, int y) {
    tabuleiro.posicoes[y][x] = peca;

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro.posicoes[i][j] == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro,
                                    int x, int y, int peca) {
    return tabuleiro.posicoes[y][x] == peca;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
    return tabuleiro.posicoes[y][x] == 0;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    return x >= 0 && x <= 2 && y >= 0 && y <= 2;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        putchar('\t');
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            switch (tabuleiro.posicoes[i][j]) {
                case 0: {
                    putchar('-');
                    break;
                }
                case PECA_1: {
                    putchar('X');
                    break;
                }
                case PECA_2: {
                    putchar('0');
                    break;
                }
                default: {
                    break;
                }
            }
        }
        putchar('\n');
    }
}
