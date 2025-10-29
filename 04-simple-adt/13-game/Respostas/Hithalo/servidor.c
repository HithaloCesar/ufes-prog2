#include "servidor.h"
#include <stdio.h>

Servidor leRegistrosServidor() {
    Servidor servidor;
    servidor.nPartidas = 0;
    servidor.nJogadores = 0;

    int idJogador1;
    while (scanf("%d", &idJogador1) == 1 && idJogador1 != -1) {
        servidor.partidas[servidor.nPartidas++] = leRegistro(idJogador1);
    }

    return servidor;
}

Servidor processaPartidas(Servidor s) {
    for (int i = 0; i < s.nPartidas; i++) {
        int idJogador1 = getIdJogador1doRegistro(s.partidas[i]);
        int idJogador2 = getIdJogador2doRegistro(s.partidas[i]);

        int indiceJogador1 = buscaPosicaoJogadorServidor(s, idJogador1);
        int indiceJogador2 = buscaPosicaoJogadorServidor(s, idJogador2);

        if (indiceJogador1 == -1) {
            indiceJogador1 = s.nJogadores;
            s.jogadores[s.nJogadores++] = inicializaJogador(idJogador1);
        }
        if (indiceJogador2 == -1) {
            indiceJogador2 = s.nJogadores;
            s.jogadores[s.nJogadores++] = inicializaJogador(idJogador2);
        }

        int recursosJogador1 = getQtdeRecursos1doRegistro(s.partidas[i]);
        int recursosJogador2 = getQtdeRecursos2doRegistro(s.partidas[i]);

        if (getIdVencedordoRegistro(s.partidas[i]) == -1) { // Empate
            int pontuacao = (recursosJogador1 - recursosJogador2) / 2;

            s.jogadores[indiceJogador1] = adicionaEmpateAoJogador(
                s.jogadores[indiceJogador1]
            );
            s.jogadores[indiceJogador1] = somaPontuacaoJogador(
                s.jogadores[indiceJogador1], -pontuacao
            );

            s.jogadores[indiceJogador2] = adicionaEmpateAoJogador(
                s.jogadores[indiceJogador2]
            );
            s.jogadores[indiceJogador2] = somaPontuacaoJogador(
                s.jogadores[indiceJogador2], pontuacao
            );
        } else if (getIdVencedordoRegistro(s.partidas[i]) == idJogador1) {
            s.jogadores[indiceJogador1] = adicionaVitoriaAoJogador(
                s.jogadores[indiceJogador1]
            );
            s.jogadores[indiceJogador2] = adicionaDerrotaAoJogador(
                s.jogadores[indiceJogador2]
            );

            int pontuacao = recursosJogador1 - recursosJogador2;
            if (recursosJogador1 < recursosJogador2) {
                pontuacao *= -1.5;
            }

            s.jogadores[indiceJogador1] = somaPontuacaoJogador(
                s.jogadores[indiceJogador1], pontuacao
            );
            s.jogadores[indiceJogador2] = somaPontuacaoJogador(
                s.jogadores[indiceJogador2], -pontuacao
            );
        } else {
            s.jogadores[indiceJogador2] = adicionaVitoriaAoJogador(
                s.jogadores[indiceJogador2]
            );
            s.jogadores[indiceJogador1] = adicionaDerrotaAoJogador(
                s.jogadores[indiceJogador1]
            );

            int pontuacao = recursosJogador2 - recursosJogador1;
            if (recursosJogador2 < recursosJogador1) {
                pontuacao *= -1.5;
            }

            s.jogadores[indiceJogador2] = somaPontuacaoJogador(
                s.jogadores[indiceJogador2], pontuacao
            );
            s.jogadores[indiceJogador1] = somaPontuacaoJogador(
                s.jogadores[indiceJogador1], -pontuacao
            );
        }
    }

    return s;
}

int buscaPosicaoJogadorServidor(Servidor s, int idJog) {
    for (int i = 0; i < s.nJogadores; i++) {
        if (s.jogadores[i].id == idJog) {
            return i;
        }
    }

    return -1;
}

void criaRelatorioServidor(Servidor s) {
    int nJogadores;
    scanf("%d\n", &nJogadores);

    for (int i = 0; i < nJogadores; i++) {
        int idJogador;
        scanf("%d ", &idJogador);

        int indiceJogador = buscaPosicaoJogadorServidor(s, idJogador);

        if (indiceJogador == -1) {
            printf("Jogador %d: -\n", idJogador);
        } else {
            printaJogador(s.jogadores[indiceJogador]);
        }
    }
}
