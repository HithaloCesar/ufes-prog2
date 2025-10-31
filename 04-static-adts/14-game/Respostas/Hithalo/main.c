#include <stdlib.h>
#include "servidor.h"

int main(void) {
    Servidor servidor = leRegistrosServidor();
    servidor = processaPartidas(servidor);
    criaRelatorioServidor(servidor);

    return EXIT_SUCCESS;
}
