#include "relatorio.h"
#include <stdio.h>

void geraRelatorio(
    tEquipe equipes[],
    int nEquipes,
    tJogador jogadores[],
    int nJogadores
) {
    int campeaoId = 0;
    int campeaoIndice = 0;
    char campeaoNome[TAM_MAX_NOME];
    int campeaoPontos = 0;

    int artilheiroIndice = 0;
    int artilheiroGols = 0;
    char artilheiroNome[TAM_MAX_NOME];
    char artilheiroNomeEquipe[TAM_MAX_NOME];
    char artilheiroIndiceEquipe = 0;

    for (int i = 0; i < nEquipes; i++) {
        campeaoPontos = tEquipe_getNumPontos(equipes[campeaoIndice]);
        if (tEquipe_getNumPontos(equipes[i]) > campeaoPontos) {
            campeaoId = tEquipe_getIdUnico(equipes[i]);
            campeaoIndice = i;
        }

        for (int j = 0; j < nJogadores; j++) {
            int idJ = tJogador_getIdUnico(jogadores[j]);
            int jogadorEquipeId = tJogador_getIdEquipe(jogadores[j]);
            if (jogadorEquipeId == tEquipe_getIdUnico(equipes[i])) {
                int golsJogador = tEquipe_getQtdeGolsJogador(equipes[i], idJ);
                if (golsJogador > artilheiroGols) {
                    artilheiroIndice = j;
                    artilheiroGols = golsJogador;
                    artilheiroIndiceEquipe = i;
                }
            }
        }
    }

    tEquipe_copiaNome(equipes[campeaoIndice], campeaoNome);
    int campeaoJogos = tEquipe_getNumJogos(equipes[campeaoIndice]);
    float aproveitamento = 100.0 * campeaoPontos / (3 * campeaoJogos);

    tJogador_copiaNome(jogadores[artilheiroIndice], artilheiroNome);
    tEquipe_copiaNome(equipes[artilheiroIndiceEquipe], artilheiroNomeEquipe);

    printf("EQUIPE CAMPEA: %s ", campeaoNome);
    printf("(%d) ", tEquipe_getIdUnico(equipes[campeaoIndice]));
    printf("P:%d ", campeaoPontos);
    printf("J:%d ", tEquipe_getNumJogos(equipes[campeaoIndice]));
    printf("V:%d ", tEquipe_getNumeroVitorias(equipes[campeaoIndice]));
    printf("E:%d ", tEquipe_getNumeroEmpates(equipes[campeaoIndice]));
    printf("D:%d ", tEquipe_getNumeroDerrotas(equipes[campeaoIndice]));
    printf("GP:%d ", tEquipe_getNumeroGolsPro(equipes[campeaoIndice]));
    printf("GC:%d ", tEquipe_getNumeroGolsContra(equipes[campeaoIndice]));
    printf("SG:%d ", tEquipe_getSaldogols(equipes[campeaoIndice]));
    printf("AP:%.2f%%\n", aproveitamento);

    printf("ARTILHEIRO: %s ", artilheiroNome);
    printf("(%s) ", artilheiroNomeEquipe);
    printf("- %d GOLS\n", artilheiroGols);
}
