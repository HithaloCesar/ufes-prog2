#include "paciente.h"
#include <stdio.h>
#include <string.h>

Paciente criaPaciente(
    char *nome,
    char *cartaoSus,
    char genero,
    Data dataNasc
) {
    Paciente paciente;
    strcpy(paciente.nome, nome);
    strcpy(paciente.cartaoSus, cartaoSus);
    paciente.genero = genero;
    paciente.dataNasc = dataNasc;
    paciente.numLesoes = 0;

    return paciente;
}

Paciente lerPaciente() {
    char nome[MAX_NOME_PAC];
    char cartaoSus[MAX_CARTAO_SUS];
    char genero;

    scanf(" %[^\n]\n", nome);
    Data dataNasc = lerData();
    scanf(" %[^\n]\n", cartaoSus);
    scanf(" %c\n", &genero);

    return criaPaciente(nome, cartaoSus, genero, dataNasc);
}

Paciente vinculaLesaoPaciente(Paciente p, Lesao l) {
    // char cartaoSusLesao[MAX_CARTAO_LES];
    // getCartaoSusLesao(l, cartaoSusLesao);

    // if (!strcmp(p.cartaoSus, cartaoSusLesao) && p.numLesoes < MAX_LESOES) {
        p.lesoes[p.numLesoes++] = l;
    // }

    return p;
}

int calculaIdadePaciente(Paciente p, Data dataBase) {
    return diferencaAnoData(p.dataNasc, dataBase);
}

void getCartaoSusPaciente(Paciente p, char *cartaoSus) {
    strcpy(cartaoSus, p.cartaoSus);
}

int getNumLesoesPaciente(Paciente p) {
    return p.numLesoes;
    // onde usar?
}

int qtdLesoesCirurgicasPaciente(Paciente p) {
    int qtdCirurgias = 0;
    for (int i = 0; i < p.numLesoes; i++) {
        if (verificaCirurgicaLesao(p.lesoes[i])) {
            qtdCirurgias++;
        }
    }

    return qtdCirurgias;
}

void imprimePaciente(Paciente p) {
    if (p.numLesoes == 0) {
        return;
    }

    printf("- %s - ", p.nome);

    const char *sep = "";
    for (int i = 0; i < p.numLesoes; i++) {
        printf("%s", sep);
        imprimeIdLesao(p.lesoes[i]);
        sep = " ";
    }

    putchar('\n');
}
