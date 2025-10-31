#include "empresa.h"
#include <stdio.h>

tEmpresa criaEmpresa(int id) {
    tEmpresa empresa;
    empresa.id = id;
    empresa.qtdFuncionarios = 0;

    return empresa;
}

tEmpresa leEmpresa() {
    // int id;
    // scanf("%d", &id);

    // return criaEmpresa(id);

    int id, qtdFuncionarios;
    scanf("%d %d", &id, &qtdFuncionarios);
    tEmpresa empresa = criaEmpresa(id);

    for (int i = 0; i < qtdFuncionarios; i++) {
        tFuncionario funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);
    }

    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(
    tEmpresa empresa,
    tFuncionario funcionario
) {
    for (int i = 0; i < empresa.qtdFuncionarios; i++) {
        if (empresa.funcionarios[i].id == funcionario.id) {
            printf("A empresa %d ja possui um funcionario com o id %d\n",
                empresa.id, funcionario.id
            );

            return empresa;
        }
    }

    empresa.funcionarios[empresa.qtdFuncionarios++] = funcionario;

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa) {
    printf("Empresa %d:\n", empresa.id);
    for (int i = 0; i < empresa.qtdFuncionarios; i++) {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}
