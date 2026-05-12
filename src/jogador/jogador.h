#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

#include "../inventario/inventario.h"
#include "../item/item.h"

class Jogador {
    private:
        int id;
        std::string nome;
        std::string classe;
        int pontuacao;
        Inventario inventario;
    public:
        Jogador(int id, std::string nome, std::string classe);
        void adicionarPontuacao(int valor);
        void removerPontuacao(int valor);
        void inserirItem(Item item);
        void removerItem(Item item);
        void exibirPerfil();
        std::string getNome();
        int getId();
        int getPontuacao();
};

#endif