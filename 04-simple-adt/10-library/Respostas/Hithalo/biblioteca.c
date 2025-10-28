#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

tBiblioteca inicializarBiblioteca() {
    tBiblioteca biblioteca;
    biblioteca.tamanho = 0;

    return biblioteca;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro) {
    if (biblioteca.tamanho >= MAX_LIVROS) {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
        return biblioteca;
    }

    biblioteca.livros[biblioteca.tamanho++] = livro;
    printf("Livro adicionado com sucesso!\n");

    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo) {
    int indiceLivro = -1;

    for (int i = 0; i < biblioteca.tamanho; i++) {
        if (!verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo)) {
            indiceLivro = i;
            break;
        }
    }

    if (indiceLivro >= 0) {
        for (int i = indiceLivro; i < biblioteca.tamanho - 1; i++) {
            biblioteca.livros[i] = biblioteca.livros[i + 1];
        }
        biblioteca.tamanho--;
        printf("Livro removido com sucesso!\n");
    } else {
        printf("Livro nao encontrado na biblioteca.\n");
    }

    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo) {
    return strcmp(livro.titulo, titulo);
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca) {
    if (biblioteca.tamanho > 0) {
        printf("Lista de Livros na Biblioteca:\n");
        for (int i = 0; i < biblioteca.tamanho; i++) {
            imprimeLivro(biblioteca.livros[i]);
        }
    } else {
        printf("A biblioteca esta vazia!\n");
    }
}
