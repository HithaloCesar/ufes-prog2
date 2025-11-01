#include "equipe.h"
#include <stdio.h>
#include <string.h>

void tEquipe_copiaNome(tEquipe e, char dst[]) {
    strcpy(dst, e.nome);
}

int tEquipe_getNumeroJogadores(tEquipe e) {
    return e.nJogadores;
}

int tEquipe_getNumeroVitorias(tEquipe e) {
    return e.nVitorias;
}

int tEquipe_getNumeroDerrotas(tEquipe e) {
    return e.nDerrotas;
}

int tEquipe_getNumeroEmpates(tEquipe e) {
    return e.nEmpates;
}

int tEquipe_getIdUnico(tEquipe e) {
    return e.idUnico;
}

int tEquipe_getNumeroGolsPro(tEquipe e) {
    return e.nGolsPro;
}

int tEquipe_getNumeroGolsContra(tEquipe e) {
    return e.nGolsContra;
}

int tEquipe_getNumPontos(tEquipe e) {
    return 3 * e.nVitorias + e.nEmpates;
}

int tEquipe_getNumJogos(tEquipe e) {
    return e.nVitorias + e.nEmpates + e.nDerrotas;
}

int tEquipe_getSaldogols(tEquipe e) {
    return e.nGolsPro - e.nGolsContra;
}

int tEquipe_getQtdeGolsJogador(tEquipe e, int idJogador) {
    int nGols = 0;
    for (int i = 0; i < e.nGolsPro; i++) {
        if (e.idGols[i] == idJogador) {
            nGols++;
        }
    }

    return nGols;
}

tEquipe tEquipe_incrementaVitorias(tEquipe e) {
    e.nVitorias++;

    return e;
}

tEquipe tEquipe_incrementaDerrotas(tEquipe e) {
    e.nDerrotas++;

    return e;
}

tEquipe tEquipe_incrementaEmpates(tEquipe e) {
    e.nEmpates++;

    return e;
}

tEquipe tEquipe_incrementaNumeroJogadores(tEquipe e) {
    e.nJogadores++;

    return e;
}

tEquipe tEquipe_adicionaGolPro(tEquipe e, int idJogador) {
    e.idGols[e.nGolsPro++] = idJogador;

    return e;
}

tEquipe tEquipe_adicionaGolsContra(tEquipe e, int nGols) {
    e.nGolsContra += nGols;

    return e;
}

tEquipe leEquipe() {
    tEquipe equipe;
    equipe.nJogadores = 0;
    equipe.nVitorias = 0;
    equipe.nEmpates = 0;
    equipe.nDerrotas = 0;
    equipe.nGolsPro = 0;
    equipe.nGolsContra = 0;

    scanf("%d", &equipe.idUnico);
    scanf(" %[^\n]", equipe.nome);

    return equipe;
}
