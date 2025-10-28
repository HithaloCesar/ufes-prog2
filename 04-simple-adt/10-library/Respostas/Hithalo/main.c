#include <stdlib.h>
#include <stdio.h>
#include "biblioteca.h"

typedef enum {
    OPERATION_ADD = 1,
    OPERATION_DEL,
    OPERATION_LIST
} tOperation;

int main(void) {
    int qtdOperacoes;
    scanf("%d", &qtdOperacoes);

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    putchar('\n');

    tBiblioteca biblioteca = inicializarBiblioteca();

    int operation;
    for (int i = 0; i < qtdOperacoes; i++) {
        scanf("%d", &operation);

        switch (operation) {
            case OPERATION_ADD: {
                tLivros livro = lerLivro();
                biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
                break;
            }

            case OPERATION_DEL: {
                char titulo[100];
                scanf(" %[^\n]", titulo);
                biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
                break;
            }

            case OPERATION_LIST: {
                listarLivrosDaBiblioteca(biblioteca);
                break;
            }

            default: {
                printf("Operacao invalida!\n");
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}
