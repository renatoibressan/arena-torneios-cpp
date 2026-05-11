#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>

#include "jogador.h"
#include "fila_partidas.h"
#include "historico_acoes.h"

class Sistema {
    private:
        std::vector<Jogador> jogadores;
        FilaPartidas fila;
        HistoricoAcoes historico;
    public:
        void executar();
        void menu();
        void cadastrarJogador();
        void iniciarPartida();
};


#endif