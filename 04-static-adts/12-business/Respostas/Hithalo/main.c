#include <stdlib.h>
#include <stdio.h>
#include "loja.h"

#define MAX_LOJAS 4

typedef enum {
    OPERACAO_SAIR,
    OPERACAO_ABRIR,
    OPERACAO_CONTRATAR,
    OPERACAO_REGISTRAR,
    OPERACAO_RELATORIO
} tOperacao;

int main(void) {
    int maxQtdLojas;
    scanf("%d\n", &maxQtdLojas);

    tLoja lojas[MAX_LOJAS];
    int qtdLojas = 0;

    int operacao;
    while (scanf(" %d\n", &operacao) == 1 && operacao != OPERACAO_SAIR) {
        switch (operacao) {
            case OPERACAO_ABRIR: {
                int id;
                float aluguel;
                scanf("%d %f\n", &id, &aluguel);
                lojas[qtdLojas++] = AbreLoja(id, aluguel);

                break;
            }

            case OPERACAO_CONTRATAR: {
                char nome[50];
                float salario;
                float prct_comissao;
                scanf(" %s %f %f\n", nome, &salario, &prct_comissao);
                tVendedor vendedor = RegistraVendedor(
                    nome, salario, prct_comissao
                );

                int idLoja;
                scanf("%d\n", &idLoja);
                for (int i = 0; i < qtdLojas; i++) {
                    if (VerificaIdLoja(lojas[i], idLoja)) {
                        lojas[i] = ContrataVendedor(lojas[i], vendedor);
                    }
                }

                break;
            }

            case OPERACAO_REGISTRAR: {
                int idLoja;
                char nome[50];
                float valor;
                scanf(" %d %s %f\n", &idLoja, nome, &valor);

                for (int i = 0; i < qtdLojas; i++) {
                    if (VerificaIdLoja(lojas[i], idLoja)) {
                        lojas[i] = RegistraVenda(lojas[i], nome, valor);
                    }
                }

                break;
            }

            case OPERACAO_RELATORIO: {
                for (int i = 0; i < qtdLojas; i++) {
                    lojas[i] = CalculaLucro(lojas[i]);
                    ImprimeRelatorioLoja(lojas[i]);
                }

                break;
            }

            default: {
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
