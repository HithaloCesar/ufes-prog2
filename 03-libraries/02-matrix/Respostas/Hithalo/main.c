#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_utils.h"

#define MATRIX_MAX_ROWS 16
#define MATRIX_MAX_COLS 16

typedef enum {
    MATRIX_OP_ADD = 1,
    MATRIX_OP_SUB = 2,
    MATRIX_OP_MUL = 3,
    MATRIX_OP_MUL_SCALAR = 4,
    MATRIX_OP_TRANS = 5,
    MATRIX_OP_EXIT = 6
} matrix_op;

int ask_for_option(void) {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");

    int option;
    scanf("%d", &option);
    putchar('\n');

    return option;
}

int main(void) {
    int rows1, cols1;
    scanf("%d %d", &rows1, &cols1);
    int matrix1[MATRIX_MAX_ROWS][MATRIX_MAX_COLS];
    matrix_read(rows1, cols1, matrix1);

    int rows2, cols2;
    scanf("%d %d", &rows2, &cols2);
    int matrix2[MATRIX_MAX_ROWS][MATRIX_MAX_COLS];
    matrix_read(rows2, cols2, matrix2);

    while (true) {
        bool running = true;

        int option = ask_for_option();
        int matrix_result[MATRIX_MAX_ROWS][MATRIX_MAX_COLS];

        switch (option) {
            case MATRIX_OP_ADD: {
                if (possible_matrix_sum(rows1, cols1, rows2, cols2)) {
                    matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2,
                               matrix_result);
                    matrix_print(rows1, cols1, matrix_result);
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            }
            case MATRIX_OP_SUB: {
                if (possible_matrix_sub(rows1, cols1, rows2, cols2)) {
                    matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2,
                               matrix_result);
                    matrix_print(rows1, cols1, matrix_result);
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            }
            case MATRIX_OP_MUL: {
                if (possible_matrix_multiply(cols1, rows2)) {
                    matrix_multiply(rows1, cols1, matrix1,
                                    rows2, cols2, matrix2,
                                    matrix_result);
                    matrix_print(rows1, cols2, matrix_result);
                } else {
                    printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
                }
                break;
            }
            case MATRIX_OP_MUL_SCALAR: {
                int scalar;
                int matrix_to_operate;
                scanf("%d %d", &scalar, &matrix_to_operate);
                if (matrix_to_operate == 1) {
                    scalar_multiply(rows1, cols1, matrix1, scalar);
                    matrix_print(rows1, cols1, matrix1);
                } else if (matrix_to_operate == 2) {
                    scalar_multiply(rows2, cols2, matrix2, scalar);
                    matrix_print(rows2, cols2, matrix2);
                }
                break;
            }
            case MATRIX_OP_TRANS: {
                transpose_matrix(rows1, cols1, matrix1, matrix_result);
                matrix_print(cols1, rows1, matrix_result);
                transpose_matrix(rows2, cols2, matrix2, matrix_result);
                matrix_print(cols2, rows2, matrix_result);
                break;
            }
            case MATRIX_OP_EXIT: {
                running = false;
                break;
            }
        }

        putchar('\n');

        if (!running) {
            break;
        }
    }

    return EXIT_SUCCESS;
}
