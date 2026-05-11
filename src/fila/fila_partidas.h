#ifndef FILA_PARTIDAS_H
#define FILA_PARTIDAS_H

#include <queue>

#include "jogador.h"

class FilaPartidas {
    private:
        std::queue<Jogador*> fila;
    public:
        void entrarFila(Jogador* jogador);
        Jogador* iniciarPartida();
        void mostrarFila();
};

#endif