#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "conta.h"

#define MAX_CONTAS 32

typedef enum Operacao {
    OPERACAO_EXIT,
    OPERACAO_SAQUE,
    OPERACAO_DEPOSITO,
    OPERACAO_CADASTRO,
    OPERACAO_RELATORIO
} tOperacao;

int main(void) {
    int maxQtdContas;
    scanf(" %d", &maxQtdContas);

    tConta contas[MAX_CONTAS];
    int qtdContas = 0;

    int operation;
    while (scanf(" %d", &operation) == 1 && operation != OPERACAO_EXIT) {
        switch (operation) {
            case OPERACAO_SAQUE: {
                int numero;
                float valor;
                scanf(" %d %f", &numero, &valor);

                bool contaEncontrada = false;
                for (int i = 0; i < qtdContas; i++) {
                    if (VerificaConta(contas[i], numero)) {
                        contas[i] = SaqueConta(contas[i], valor);
                        contaEncontrada = true;
                        break;
                    }
                }

                if (!contaEncontrada) {
                    fprintf(stderr, "ERRO: Conta nao encontrada!\n");
                }

                break;
            }
            case OPERACAO_DEPOSITO: {
                int numero;
                float valor;
                scanf(" %d %f", &numero, &valor);

                bool contaEncontrada = false;
                for (int i = 0; i < qtdContas; i++) {
                    if (VerificaConta(contas[i], numero)) {
                        contas[i] = DepositoConta(contas[i], valor);
                        contaEncontrada = true;
                        break;
                    }
                }

                if (!contaEncontrada) {
                    fprintf(stderr, "ERRO: Conta nao encontrada!\n");
                }

                break;
            }
            case OPERACAO_CADASTRO: {
                if (qtdContas >= maxQtdContas) {
                    fprintf(stderr, "ERRO: Limite de contas ja alcancado!\n");
                    break;
                }

                char nome[20], cpf[15];
                int numero;
                scanf(" %s %s %d", nome, cpf, &numero);

                tUsuario usuario = CriaUsuario(nome, cpf);
                contas[qtdContas++] = CriaConta(numero, usuario);

                break;
            }
            case OPERACAO_RELATORIO: {
                printf("===| Imprimindo Relatorio |===\n");
                for (int i = 0; i < qtdContas; i++) {
                    ImprimeConta(contas[i]);
                }

                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
