#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>

#include "../jogador/jogador.h"
#include "../fila/fila_partidas.h"
#include "../historico/historico_acoes.h"

class Sistema {
    private:
        std::vector<Jogador> jogadores;
        FilaPartidas fila;
        HistoricoAcoes historico;
    public:
        void menuPrincipal();
        void cadastrarJogador();
        void iniciarPartida();
};

#endif