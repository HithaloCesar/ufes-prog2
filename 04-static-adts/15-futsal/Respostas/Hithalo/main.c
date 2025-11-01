#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "jogador.h"
#include "equipe.h"
#include "partida.h"
#include "busca.h"
#include "inconsistencias.h"
#include "relatorio.h"

#define MAX_EQUIPES 20
#define MAX_JOGADORES 200

typedef enum {
    OPERACAO_EQUIPE = 'E',
    OPERACAO_JOGADOR = 'J',
    OPERACAO_PARTIDA = 'P',
    OPERACAO_FINALIZAR = 'F'
} tOperacao;

int main(void) {
    tEquipe equipes[MAX_EQUIPES];
    int nEquipes = 0;
    tJogador jogadores[MAX_JOGADORES];
    int nJogadores = 0;
    int nPartidas = 0;

    char operacao;
    while (scanf(" %c", &operacao) == 1 && operacao != OPERACAO_FINALIZAR) {
        switch (operacao) {
            case OPERACAO_EQUIPE: {
                equipes[nEquipes++] = leEquipe();

                break;
            }
            case OPERACAO_JOGADOR: {
                jogadores[nJogadores] = lerJogador();
                int equipeId = tJogador_getIdEquipe(jogadores[nJogadores]);
                int equipeIndice = tEquipe_encontraIndiceVetorComIdUnico(
                    equipes, nEquipes, equipeId
                );
                equipes[equipeIndice] = tEquipe_incrementaNumeroJogadores(
                    equipes[equipeIndice]
                );

                nJogadores++;

                break;
            }
            case OPERACAO_PARTIDA: {
                tPartida partida = tPartida_lerPartida();

                int equipe1Gols = tPartida_getNumGolsEquipe1(partida);
                int equipe2Gols = tPartida_getNumGolsEquipe2(partida);

                int equipe1Indice = tEquipe_encontraIndiceVetorComIdUnico(
                    equipes, nEquipes, tPartida_getIdEquipe1(partida)
                );
                int equipe2Indice = tEquipe_encontraIndiceVetorComIdUnico(
                    equipes, nEquipes, tPartida_getIdEquipe2(partida)
                );

                int nJogadoresEquipe1 = tEquipe_getNumeroJogadores(
                    equipes[equipe1Indice]
                );
                int nJogadoresEquipe2 = tEquipe_getNumeroJogadores(
                    equipes[equipe2Indice]
                );

                bool woEquipe1 = nJogadoresEquipe2 < 5;
                bool woEquipe2 = nJogadoresEquipe1 < 5;

                for (int i = 0; i < equipe1Gols; i++) {
                    int jogadorId;
                    scanf("%d", &jogadorId);
                    equipes[equipe1Indice] = tEquipe_adicionaGolPro(
                        equipes[equipe1Indice], jogadorId
                    );
                }

                for (int i = 0; i < equipe2Gols; i++) {
                    int jogadorId;
                    scanf("%d", &jogadorId);
                    equipes[equipe2Indice] = tEquipe_adicionaGolPro(
                        equipes[equipe2Indice], jogadorId
                    );
                }

                equipes[equipe1Indice] = tEquipe_adicionaGolsContra(
                    equipes[equipe1Indice], equipe2Gols
                );

                equipes[equipe2Indice] = tEquipe_adicionaGolsContra(
                    equipes[equipe2Indice], equipe1Gols
                );

                if (equipe1Gols > equipe2Gols || woEquipe1) {
                    equipes[equipe1Indice] = tEquipe_incrementaVitorias(
                        equipes[equipe1Indice]
                    );
                    equipes[equipe2Indice] = tEquipe_incrementaDerrotas(
                        equipes[equipe2Indice]
                    );
                } else if (equipe2Gols > equipe1Gols || woEquipe2) {
                    equipes[equipe2Indice] = tEquipe_incrementaVitorias(
                        equipes[equipe2Indice]
                    );
                    equipes[equipe1Indice] = tEquipe_incrementaDerrotas(
                        equipes[equipe1Indice]
                    );
                } else {
                    equipes[equipe1Indice] = tEquipe_incrementaEmpates(
                        equipes[equipe1Indice]
                    );
                    equipes[equipe2Indice] = tEquipe_incrementaEmpates(
                        equipes[equipe2Indice]
                    );
                }

                nPartidas++;

                break;
            }
        }
    }

    if (!verificaInconsistencias(nPartidas, nEquipes, equipes)) {
        geraRelatorio(equipes, nEquipes, jogadores, nJogadores);
    }

    return EXIT_SUCCESS;
}
