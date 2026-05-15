#ifndef SISTEMA_PARTIDAS_H
#define SISTEMA_PARTIDAS_H

#include "../models/jogador.h"

struct ResultadoPartida {
    int idVencedor;
    int idPerdedor;
    int turnos;
};

ResultadoPartida executarPartida(Jogador *j1, Jogador *j2);

#endif