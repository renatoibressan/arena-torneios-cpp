#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>

#include "fila_partidas.h"
#include "historico_acoes.h"
#include "../models/jogador.h"
#include "../repository/arquivo.h"

class Sistema {
    private:
        std::vector<Jogador> jogadores;
        FilaPartidas fila;
        HistoricoAcoes historico;
        Arquivo arquivo;
        int ultimoId;
        bool ordenadoPorId;
        bool ordenadoPorPontuacao;
        int gerarNovoId();
    public:
        Sistema();
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
        void exibirClassificacao();
        void desfazerHistorico();
        void mostrarHistorico();
        void salvarDados();
        void carregarDados();
};

#endif