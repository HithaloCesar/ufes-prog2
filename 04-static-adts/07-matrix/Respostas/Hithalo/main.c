#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "matrix_utils.h"

typedef enum matrixOperation {
    OPERATION_ADD = 1,
    OPERATION_SUB,
    OPERATION_MUL,
    OPERATION_MUL_S,
    OPERATION_TRANS,
    OPERATION_EXIT
} tOperation;

int main(void) {
    int rows, cols;

    scanf("%d %d", &rows, &cols);
    tMatrix matrix1 = MatrixCreate(rows, cols);
    matrix1 = MatrixRead(matrix1);

    scanf("%d %d", &rows, &cols);
    tMatrix matrix2 = MatrixCreate(rows, cols);
    matrix2 = MatrixRead(matrix2);

    bool running = true;
    while (running) {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");

        int operation;
        scanf("%d", &operation);

        switch (operation) {
            case (OPERATION_ADD): {
                if  (PossibleMatrixSum(matrix1, matrix2)) {
                    MatrixPrint(MatrixAdd(matrix1, matrix2));
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                    putchar('\n');
                }

                break;
            }

            case (OPERATION_SUB): {
                if  (PossibleMatrixSub(matrix1, matrix2)) {
                    MatrixPrint(MatrixSub(matrix1, matrix2));
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                    putchar('\n');
                }

                break;
            }

            case OPERATION_MUL: {
                if (PossibleMatrixMultiply(matrix1, matrix2)) {
                    MatrixPrint(MatrixMultiply(matrix1, matrix2));
                } else {
                    printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
                    putchar('\n');
                }

                break;
            }

            case OPERATION_MUL_S: {
                int scalar, matrixId;
                scanf("%d %d", &scalar, &matrixId);

                if (matrixId == 1) {
                    matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                    MatrixPrint(matrix1);
                } else if (matrixId == 2) {
                    matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                    MatrixPrint(matrix2);
                }

                break;
            }

            case OPERATION_TRANS: {
                MatrixPrint(TransposeMatrix(matrix1));
                MatrixPrint(TransposeMatrix(matrix2));

                break;
            }

            case OPERATION_EXIT: {
                running = false;

                break;
            }

            default: {
                fprintf(stderr, "ERROR: Invalid input!\n");
                running = false;

                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
