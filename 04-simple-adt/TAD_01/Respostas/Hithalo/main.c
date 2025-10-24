#include <stdlib.h>
#include "jogo.h"

int main(void) {
    tJogo game = CriaJogo();

    do {
        ComecaJogo(game);
    } while (ContinuaJogo(game));

    return EXIT_SUCCESS;
}
