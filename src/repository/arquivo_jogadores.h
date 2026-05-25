#ifndef ARQUIVO_JOGADORES_H
#define ARQUIVO_JOGADORES_H

#include <vector>
#include <string>

#include "../models/jogador.h"

class ArquivoJogadores {
    private:
        std::string caminho;
    public:
        ArquivoJogadores(const std::string& caminho);
        bool salvarJogadores(const std::vector<Jogador>& jogadores) const;
        bool carregarJogadores(std::vector<Jogador>& jogadores, int& ultimoIdJogadores) const;
        bool arquivoExiste() const;
};

#endif