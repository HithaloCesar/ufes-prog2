#include "jogador.h"
#include <stdio.h>

Jogador inicializaJogador(int id) {
    Jogador jogador;
    jogador.id = id;
    jogador.vitorias = 0;
    jogador.derrotas = 0;
    jogador.empates = 0;
    jogador.pontuacao = 0;
    strcpy(jogador.league, calculaLeague(jogador));

    return jogador;
}

char* calculaLeague(Jogador j) {
    if (j.pontuacao <= 200) {
        return "ROOKIE";
    }
    if (j.pontuacao <= 400) {
        return "IRON";
    }
    if (j.pontuacao <= 600) {
        return "BRONZE";
    }
    if (j.pontuacao <= 800) {
        return "SILVER";
    }
    if (j.pontuacao <= 1000) {
        return "GOLD";
    }
    if (j.pontuacao <= 1500) {
        return "PLATINUM";
    }
    if (j.pontuacao <= 2000) {
        return "DIAMOND";
    }

    return "MASTER";
}

void printaJogador(Jogador j) {
    printf("Jogador %d: %d/%d/%d (%s)\n",
        j.id, j.vitorias, j.derrotas, j.empates, calculaLeague(j)
    );
}

int getIdJogador(Jogador j) {
    return j.id;
}

Jogador somaPontuacaoJogador(Jogador j, int pont) {
    j.pontuacao += pont;

    if (j.pontuacao < 0) {
        j.pontuacao = 0;
    }

    return j;
}

Jogador adicionaVitoriaAoJogador(Jogador j) {
    j.vitorias++;

    return j;
}

Jogador adicionaDerrotaAoJogador(Jogador j) {
    j.derrotas++;

    return j;
}

Jogador adicionaEmpateAoJogador(Jogador j) {
    j.empates++;

    return j;
}
