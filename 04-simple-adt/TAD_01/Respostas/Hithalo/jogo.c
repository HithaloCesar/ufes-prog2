#include "jogo.h"
#include <stdio.h>
#include <stdbool.h>

tJogo CriaJogo() {
    tJogo game;

    game.tabuleiro = CriaTabuleiro();
    game.jogador1 = CriaJogador(ID_JOGADOR_1);
    game.jogador2 = CriaJogador(ID_JOGADOR_2);

    return game;
}

void ComecaJogo(tJogo jogo) {
    tJogador *turn_player;
    bool p1_turn = true;

    while (true)  {
        if (p1_turn) {
            turn_player = &jogo.jogador1;
        } else {
            turn_player = &jogo.jogador2;
        }

        jogo.tabuleiro = JogaJogador(*turn_player, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);

        if (VenceuJogador(*turn_player, jogo.tabuleiro)) {
            printf("JOGADOR %d Venceu!\n", (*turn_player).id);
            break;
        } else if (AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            break;
        }

        p1_turn = !p1_turn;
    }
}

int AcabouJogo(tJogo jogo) {
    return !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}

int ContinuaJogo() {
    printf("Jogar novamente? (s,n)\n");

    char option;
    scanf("%*[^n,s]%c", &option);
    // Is output 06 wrong? "-1 -1" seems misplaced
    // Anyway, ignore everything until 'n' or 's' is read

    if (option == 's') {
        return 1;
    }

    return 0;
}
