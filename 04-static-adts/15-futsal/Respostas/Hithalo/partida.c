#include "partida.h"
#include <stdio.h>

int tPartida_getIdPartida(tPartida partida) {
    return partida.idPartida;
}

int tPartida_getIdEquipe1(tPartida partida) {
    return partida.idEquipe1;
}

int tPartida_getIdEquipe2(tPartida partida) {
    return partida.idEquipe2;
}

int tPartida_getNumGolsEquipe1(tPartida partida) {
    return partida.numGolsEquipe1;
}

int tPartida_getNumGolsEquipe2(tPartida partida) {
    return partida.numGolsEquipe2;
}

tPartida tPartida_lerPartida() {
    tPartida p;
    scanf("%d", &p.idPartida);
    scanf("%d", &p.idEquipe1);
    scanf("%d", &p.idEquipe2);
    scanf("%d", &p.numGolsEquipe1);
    scanf("%d", &p.numGolsEquipe2);

    return p;
}
