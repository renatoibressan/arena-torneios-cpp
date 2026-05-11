#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

#include "inventario.h"

class Jogador {
    private:
        int id;
        std::string nome;
        std::string classe;
        int pontuacao;
        Inventario inventario;
    public:
        void adicionarPontuacao(int valor);
        void removerPontuacao(int valor);
        void exibirPerfil();
        std::string getNome();
        int getId();
        int getPontuacao();
};

#endif