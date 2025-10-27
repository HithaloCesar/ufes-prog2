#include <stdio.h>
#include "funcionario.h"

tFuncionario criaFuncionario(int id, float salario) {
    tFuncionario funcionario;
    funcionario.id = id;
    funcionario.salario = salario;

    return funcionario;
}

tFuncionario leFuncionario() {
    int id;
    float salario;
    scanf("%d %f", &id, &salario);

    return criaFuncionario(id, salario);
}

int getIdFuncionario(tFuncionario funcionario) {
    return funcionario.id;
}

void imprimeFuncionario(tFuncionario funcionario) {
    printf("- Funcionario %d: RS %.2f\n", funcionario.id, funcionario.salario);
}
