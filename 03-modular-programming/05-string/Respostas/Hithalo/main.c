#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string_utils.h"

#define STRING_BUFFER_SIZE 1024

typedef enum {
    STR_OP_SIZE = 1,
    STR_OP_COPY,
    STR_OP_UPPER,
    STR_OP_LOWER,
    STR_OP_REVERSE,
    STR_OP_EXIT
} str_op;

static int ask_for_option(void);

int main(void) {
    char string[STRING_BUFFER_SIZE];
    scanf("%[^\n]", string);

    while (true) {
        bool running = true;

        int option = ask_for_option();

        switch (option) {
            case STR_OP_SIZE: {
                printf("Tamanho da string: %d\n", string_length(string));
                break;
            }
            case STR_OP_COPY: {
                char copy[STRING_BUFFER_SIZE];
                string_copy(string, copy);
                printf("String copiada: %s\n", copy);
                break;
            }
            case STR_OP_UPPER: {
                string_upper(string);
                printf("String convertida para maiusculas: %s\n", string);
                break;
            }
            case STR_OP_LOWER: {
                string_lower(string);
                printf("String convertida para minusculas: %s\n", string);
                break;
            }
            case STR_OP_REVERSE: {
                string_reverse(string);
                printf("String invertida: %s\n", string);
                break;
            }
            case STR_OP_EXIT: {
                running = false;
                break;
            }
            default: {
                running = false;
                break;
            }
        }

        if (!running) {
            break;
        }
    }

    return EXIT_SUCCESS;
}

static int ask_for_option(void) {
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");

    int option;
    scanf("%d", &option);
    putchar('\n');

    return option;
}
