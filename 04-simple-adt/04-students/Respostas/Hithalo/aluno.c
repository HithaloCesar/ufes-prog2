#include "aluno.h"
#include <stdio.h>
#include <string.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3) {
    tAluno aluno;
    strcpy(aluno.nome, nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

tAluno LeAluno() {
    char nome[50];
    int matricula, n1, n2, n3;
    scanf("%[^\n]\n", nome);
    scanf("%d\n", &matricula);
    scanf("%d %d %d\n", &n1, &n2, &n3);

    return CriaAluno(nome, matricula, n1, n2, n3);
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2) {
    int diff = aluno1.matricula - aluno2.matricula;

    if (diff > 0) {
        return 1;
    }

    if (diff < 0) {
        return -1;
    }

    return 0;
}

int CalculaMediaAluno(tAluno aluno) {
    return (aluno.n1 + aluno.n2 + aluno.n3) / 3;
}

int VerificaAprovacao(tAluno aluno) {
    return CalculaMediaAluno(aluno) >= 7;
}

void ImprimeAluno(tAluno aluno) {
    printf("%s\n", aluno.nome);
}
