#include "candidato.h"
#include <stdio.h>
#include <string.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id) {
    tCandidato candidato;

    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;

    return candidato;
}

tCandidato LeCandidato() {
    char nome[50];
    char partido[50];
    char cargo;
    int id;

    scanf(" %[^,], %[^,], %c, %d", nome, partido, &cargo, &id);
    tCandidato c = CriaCandidato(nome, partido, cargo, id);

    return c;
}

int VerificaIdCandidato(tCandidato candidato, int id) {
    return candidato.id == id;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2) {
    return candidato1.id == candidato2.id;
}

char ObtemCargo(tCandidato candidato) {
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato) {
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato) {
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos) {
    return (float)candidato.votos / totalVotos * 100.0;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos) {
    printf("%s (%s), %d voto(s), %.2f%%\n",
           candidato.nome, candidato.partido,
           candidato.votos, percentualVotos);
}
