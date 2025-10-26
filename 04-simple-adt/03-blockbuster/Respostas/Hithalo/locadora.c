#include "locadora.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

tLocadora criarLocadora() {
    tLocadora locadora;
    locadora.numFilmes = 0;
    locadora.lucro = 0;

    return locadora;
}

int verificarFilmeCadastrado(tLocadora locadora, int codigo) {
    for (int i = 0; i < locadora.numFilmes; i++) {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo)) {
            return 1;
        }
    }

    return 0;
}

tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme) {
    if (verificarFilmeCadastrado(locadora, filme.codigo)) {
        printf("Filme ja cadastrado no estoque\n");
    } else {
        locadora.filme[locadora.numFilmes++] = filme;
        printf("Filme cadastrado %d - ", filme.codigo);
        imprimirNomeFilme(filme);
        putchar('\n');
    }

    return locadora;
}

tLocadora lerCadastroLocadora(tLocadora locadora) {
    int codigo;
    while (scanf(" %d,", &codigo) == 1) {
        tFilme filme = leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora, filme);
    }

    char c = '#';
    if (scanf(" %c ", &c) != 1 || c != '#') {
        fprintf(stderr, "Invalid input\n");
        exit(EXIT_FAILURE);
    }

    return locadora;
}

tLocadora alugarFilmesLocadora(
    tLocadora locadora,
    int *codigos,
    int quantidadeCodigos
) {
    int quantidadeAlugados = 0;
    int custo = 0;

    for (int i = 0; i < quantidadeCodigos; i++) {
        bool filmeCadastrado = false;

        for (int j = 0; j < locadora.numFilmes; j++) {
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
                if (obterQtdEstoqueFilme(locadora.filme[j]) > 0) {
                    locadora.filme[j] = alugarFilme(locadora.filme[j]);
                    custo += obterValorFilme(locadora.filme[j]);
                    quantidadeAlugados++;
                } else {
                    printf("Filme %d - ", locadora.filme[j].codigo);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }

                filmeCadastrado = true;
                break;
            }
        }

        if (!filmeCadastrado) {
           printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    if (quantidadeAlugados > 0) {
        printf("Total de filmes alugados: %d com custo de R$%d\n",
            quantidadeAlugados,
            custo
        );
    }

    return locadora;
}

tLocadora lerAluguelLocadora(tLocadora locadora) {
    int codigos[MAX_FILMES];
    int quantidadeCodigos = 0;

    int codigo;
    while (scanf(" %d ", &codigo) == 1) {
        codigos[quantidadeCodigos++] = codigo;
    }

    char c = '#';
    if (scanf(" %c ", &c) != 1 || c != '#') {
        fprintf(stderr, "Invalid input\n");
        exit(EXIT_FAILURE);
    }

    return alugarFilmesLocadora(locadora, codigos, quantidadeCodigos);
}

tLocadora devolverFilmesLocadora(
    tLocadora locadora,
    int *codigos,
    int quantidadeCodigos
) {
    for (int i = 0; i < quantidadeCodigos; i++) {
        bool filmeCadastrado = false;

        for (int j = 0; j < locadora.numFilmes; j++) {
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
                if (obterQtdAlugadaFilme(locadora.filme[j]) > 0) {
                    locadora.filme[j] = devolverFilme(locadora.filme[j]);
                    locadora.lucro += obterValorFilme(locadora.filme[j]);

                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" Devolvido!\n");
                } else {
                    printf("Nao e possivel devolver o filme %d - ", codigos[i]);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                }

                filmeCadastrado = true;
                break;
            }
        }

        if (!filmeCadastrado) {
           printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    return locadora;
}

tLocadora lerDevolucaoLocadora(tLocadora locadora) {
    int codigos[MAX_FILMES];
    int quantidadeCodigos = 0;

    int codigo;
    while (scanf(" %d ", &codigo) == 1) {
        codigos[quantidadeCodigos++] = codigo;
    }

    char c = '#';
    if (scanf(" %c ", &c) != 1 || c != '#') {
        fprintf(stderr, "Invalid input\n");
        exit(EXIT_FAILURE);
    }

    return devolverFilmesLocadora(locadora, codigos, quantidadeCodigos);
}

static int compararNomesFilmesWrapper(const void *f1, const void *f2) {
    return compararNomesFilmes(*(const tFilme*)f1, *(const tFilme*)f2);
}

tLocadora ordenarFilmesLocadora(tLocadora locadora) {
    qsort(
        locadora.filme,
        locadora.numFilmes,
        sizeof(tFilme),
        compararNomesFilmesWrapper
    );

    return locadora;
}

void consultarEstoqueLocadora(tLocadora locadora) {
    printf("~ESTOQUE~\n");
    for (int i = 0; i < locadora.numFilmes; i++) {
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n",
            obterQtdEstoqueFilme(locadora.filme[i])
        );
    }
}

void consultarLucroLocadora(tLocadora locadora) {
    if (locadora.lucro > 0) {
        putchar('\n');
        printf("Lucro total R$%d\n", locadora.lucro);
    }
}
