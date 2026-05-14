#ifndef SISTEMA_PARTIDAS_H
#define SISTEMA_PARTIDAS_H

#include <vector>

#include "../jogador/jogador.h"
#include "../fila/fila_partidas.h"

struct ResultadoPartida {
    bool sucesso;
    int idVencedor;
    int idPerdedor;
    int turnos;
};

ResultadoPartida executarPartida(std::vector<Jogador>& jogadores, FilaPartidas& fila);

#endif