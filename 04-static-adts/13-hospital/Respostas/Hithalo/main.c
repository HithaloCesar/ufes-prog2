#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "paciente.h"

#define MAX_PACIENTES 100
#define HOJE_DIA 12
#define HOJE_MES 9
#define HOJE_ANO 2023

typedef enum {
    OPERACAO_PACIENTE = 'P',
    OPERACAO_LESAO = 'L',
    OPERACAO_FINALIZAR = 'F'
} tOperacao;

int main(void) {
    Paciente pacientes[MAX_PACIENTES];
    int numPacientes = 0;

    char operacao;
    bool continuarOperando = true;
    while (scanf(" %c\n", &operacao) == 1 && continuarOperando) {
        switch (operacao) {
            case OPERACAO_PACIENTE: {
                pacientes[numPacientes++] = lerPaciente();

                break;
            }

            case OPERACAO_LESAO: {
                Lesao lesao = lerLesao();
                char cartaoSusLesao[MAX_CARTAO_LES];
                getCartaoSusLesao(lesao, cartaoSusLesao);

                for (int i = 0; i < numPacientes; i++) {
                    if (!strcmp(pacientes[i].cartaoSus, cartaoSusLesao)
                        && pacientes[i].numLesoes < MAX_LESOES) {

                        pacientes[i] = vinculaLesaoPaciente(
                            pacientes[i], lesao
                        );
                    }
                }

                break;
            }

            case OPERACAO_FINALIZAR: {
                continuarOperando = false;

                Data hoje = {HOJE_DIA, HOJE_MES, HOJE_ANO};
                int somaIdades = 0;
                int numLesoes = 0;
                int numCirurgias = 0;
                for (int i = 0; i < numPacientes; i++) {
                    somaIdades += calculaIdadePaciente(pacientes[i], hoje);
                    numLesoes += getNumLesoesPaciente(pacientes[i]);
                    numCirurgias += qtdLesoesCirurgicasPaciente(pacientes[i]);
                }

                printf("TOTAL PACIENTES: %d\n", numPacientes);
                if (numPacientes > 0) {
                    printf("MEDIA IDADE (ANOS): %d\n",
                        somaIdades / numPacientes
                    );
                } else {
                    printf("MEDIA IDADE (ANOS): -\n");
                }
                printf("TOTAL LESOES: %d\n", numLesoes);
                printf("TOTAL CIRURGIAS: %d\n", numCirurgias);
                printf("LISTA DE PACIENTES:\n");
                for (int i = 0; i < numPacientes; i++) {
                    imprimePaciente(pacientes[i]);
                }

                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
