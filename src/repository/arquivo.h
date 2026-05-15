#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <vector>
#include <string>

#include "../models/jogador.h"

class Arquivo {
    private:
        std::string caminho;
    public:
        Arquivo(const std::string& caminho);
        bool salvarJogadores(const std::vector<Jogador>& jogadores) const;
        bool carregarJogadores(std::vector<Jogador>& jogadores, int& ultimoId) const;
        bool arquivoExiste() const;
};


#endif