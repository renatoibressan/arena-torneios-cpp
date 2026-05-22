#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <any>

#include "algoritmos.h"
#include "../models/jogador.h"
#include "../models/item.h"

Jogador* buscarJogadorPorNome(std::vector<Jogador>& jogadores, const std::string& nome) {
    for (Jogador& jogador : jogadores) if (jogador.getNome() == nome) return &jogador;
    return nullptr;
}

Jogador* buscarJogadorPorId(std::vector<Jogador>& jogadores, int id) {
    int esquerda = 0;
    int direita = static_cast<int>(jogadores.size()) - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (jogadores.at(meio).getId() == id) return &jogadores.at(meio);
        else if (jogadores.at(meio).getId() < id) esquerda = meio + 1;
        else direita = meio - 1;
    }
    return nullptr;
}

std::vector<std::unique_ptr<Item>>::iterator buscarItemPorNome(std::vector<std::unique_ptr<Item>>& itens, const std::string& nome) {
    return std::find_if(
        itens.begin(),
        itens.end(),
        [&](const std::unique_ptr<Item>& item) {
            return item->getNome() == nome;
        }
    );
}

bool compararIds(const Jogador& a, const Jogador& b) {
    return a.getId() < b.getId();
}

bool compararPontuacao(const Jogador* &a, const Jogador* &b) {
    return (a->getPontuacao() == b->getPontuacao()) ? a->getId() < b->getId() : a->getPontuacao() > b->getPontuacao();
}

bool compararNomeItens(const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b) {
    return a->getNome() < b->getNome();
}