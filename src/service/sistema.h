#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <memory>

#include "fila_partidas.h"
#include "historico_acoes.h"
#include "../models/jogador.h"
#include "../models/item.h"
#include "../repository/arquivo_jogadores.h"
#include "../repository/arquivo_itens.h"

class Sistema {
    private:
        std::vector<Jogador> jogadores;
        std::vector<std::unique_ptr<Item>> itensDisponiveis;
        FilaPartidas fila;
        HistoricoAcoes historico;
        ArquivoJogadores arquivoJogadores;
        ArquivoItens arquivoItens;
        int ultimoId;
        bool ordenadoPorId;
        bool ordenadoPorPontuacao;
        bool ordenadoPorNome;
        int gerarNovoId();
        bool jogadorExiste(const std::string& nome);
        bool itemExiste(const std::string& nome);
    public:
        Sistema();
        void menuPrincipal();
        void cadastrarJogador();
        void listarJogadores();
        void buscarJogador();
        void registrarItem();
        void listarItens();
        void buscarItem();
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