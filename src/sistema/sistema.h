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
        void listarJogadores();
        void buscarJogador();
        void inserirEmInventario();
        void listarInventario();
        void buscarDeInventario();
        void removerDeInventario();
        void adicionarFila();
        void mostrarFila();
        void iniciarPartida();
        void registrarHistorico();
        void desfazerHistorico();
        void mostrarHistorico();
};

#endif