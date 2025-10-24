#include "eleicao.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

tEleicao InicializaEleicao() {
    tEleicao eleicao = {0};

    int qtd_candidatos;
    scanf("%d", &qtd_candidatos);

    for (int i = 0; i < qtd_candidatos; i++) {
        tCandidato candidato = LeCandidato();
        if (ObtemCargo(candidato) == 'P') {
            eleicao.presidentes[eleicao.totalPresidentes++] = candidato;
        } else if (ObtemCargo(candidato) == 'G') {
            eleicao.governadores[eleicao.totalGovernadores++] = candidato;
        }
    }

    return eleicao;
}

static void ProcessaVoto(tCandidato candidatos[], int totalCandidatos,
                         int voto, int *votosBrancos, int *votosNulos) {
    bool nulo = true;
    for (int c = 0; c < totalCandidatos; c++) {
        if (VerificaIdCandidato(candidatos[c], voto)) {
            candidatos[c] = IncrementaVotoCandidato(candidatos[c]);
            nulo = false;
        }
    }

    if (voto == 0) {
        (*votosBrancos)++;
    } else if (nulo) {
        (*votosNulos)++;
    }
}

tEleicao RealizaEleicao(tEleicao eleicao) {
    scanf("%d", &eleicao.totalEleitores);

    if (eleicao.totalEleitores > 10) {
        printf("ELEICAO ANULADA\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < eleicao.totalEleitores; i++) {
        eleicao.eleitores[i] = LeEleitor();
    }

    for (int i = 0; i < eleicao.totalEleitores; i++) {
        for (int j = i + 1; j < eleicao.totalEleitores; j++) {
            if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])) {
                printf("ELEICAO ANULADA\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    for (int e = 0; e < eleicao.totalEleitores; e++) {
        ProcessaVoto(eleicao.presidentes,
                     eleicao.totalPresidentes,
                     ObtemVotoPresidente(eleicao.eleitores[e]),
                     &eleicao.votosBrancosPresidente,
                     &eleicao.votosNulosPresidente);

        ProcessaVoto(eleicao.governadores,
                     eleicao.totalGovernadores,
                     ObtemVotoGovernador(eleicao.eleitores[e]),
                     &eleicao.votosBrancosGovernador,
                     &eleicao.votosNulosGovernador);
    }

    return eleicao;
}

static void ImprimeVencedorCargo(const char *cargo,
                                 const tCandidato candidatos[],
                                 int totalCandidatos,
                                 int votosBrancos,
                                 int votosNulos,
                                 int votosTotal) {
    tCandidato *c_max = &candidatos[0];
    int c_max_count = 1;
    for (int c = 1; c < totalCandidatos; c++) {
        if (candidatos[c].votos > c_max->votos) {
            c_max = &candidatos[c];
            c_max_count = 1;
        } else if (candidatos[c].votos == c_max->votos) {
            c_max_count++;
        }
    }

    printf("- %s ELEITO: ", cargo);
    if (c_max_count > 1) {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    } else if (c_max->votos < votosBrancos + votosNulos) {
        printf("SEM DECISAO\n");
    } else {
        ImprimeCandidato(*c_max, CalculaPercentualVotos(*c_max, votosTotal));
    }
}

void ImprimeResultadoEleicao(tEleicao eleicao) {
    ImprimeVencedorCargo("PRESIDENTE", eleicao.presidentes,
                         eleicao.totalPresidentes,
                         eleicao.votosBrancosPresidente,
                         eleicao.votosNulosPresidente,
                         eleicao.totalEleitores);

    ImprimeVencedorCargo("GOVERNADOR", eleicao.governadores,
                         eleicao.totalGovernadores,
                         eleicao.votosBrancosGovernador,
                         eleicao.votosNulosGovernador,
                         eleicao.totalEleitores);

    printf("- NULOS E BRANCOS: %d, %d\n",
           eleicao.votosNulosPresidente + eleicao.votosNulosGovernador,
           eleicao.votosBrancosPresidente + eleicao.votosBrancosGovernador);
}
