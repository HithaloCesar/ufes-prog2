#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

#define MAX_ALUNOS 1024

static int qsortComparaMatricula(const void *a1, const void *a2);

int main(void) {
    tAluno alunos[MAX_ALUNOS];

    int qtdAlunos;
    scanf("%d\n", &qtdAlunos);
    for (int i = 0; i < qtdAlunos; i++) {
        alunos[i] = LeAluno();
    }

    qsort(alunos, qtdAlunos, sizeof(tAluno), qsortComparaMatricula);
    for (int i = 0; i < qtdAlunos; i++) {
        if (VerificaAprovacao(alunos[i])) {
            ImprimeAluno(alunos[i]);
        }
    }

    return EXIT_SUCCESS;
}

static int qsortComparaMatricula(const void *a1, const void *a2) {
    return ComparaMatricula(*(tAluno*)a1, *(tAluno*)a2);
}
