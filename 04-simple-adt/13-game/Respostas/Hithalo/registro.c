#include "registro.h"
#include <stdio.h>

Registro leRegistro(int idJogador1) {
    Registro r;
    r.idJogador1 = idJogador1;
    scanf("%d %d %d %d\n",
        &r.idJogador2, &r.idVencedor, &r.qtdeRecursos1, &r.qtdeRecursos2
    );

    return r;
}

int getIdJogador1doRegistro(Registro r) {
    return r.idJogador1;
}

int getIdJogador2doRegistro(Registro r) {
    return r.idJogador2;
}

int getIdVencedordoRegistro(Registro r) {
    return r.idVencedor;
}

int getQtdeRecursos1doRegistro(Registro r) {
    return r.qtdeRecursos1;
}

int getQtdeRecursos2doRegistro(Registro r) {
    return r.qtdeRecursos2;
}
