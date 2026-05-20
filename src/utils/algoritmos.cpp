#include <cstdlib>
#include <vector>
#include <string>
#include <any>

#include "algoritmos.h"
#include "../models/jogador.h"
#include "../models/item.h"

Jogador* buscarJogadorPorNome(std::vector<Jogador>& jogadores, const std::string nome) {
    for (Jogador& jogador : jogadores) if (jogador.getNome() == nome) return &jogador;
    return nullptr;
}

Jogador* buscarJogadorPorId(std::vector<Jogador>& jogadores, int id) {
    int esquerda = 0;
    int direita = jogadores.size() - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (jogadores.at(meio).getId() == id) return &jogadores.at(meio);
        else if (jogadores.at(meio).getId() < id) esquerda = meio + 1;
        else direita = meio - 1;
    }
    return nullptr;
}

Item* buscarItemPorNome(std::vector<Item>& itens, const std::string nome) {
    int esquerda = 0;
    int direita = itens.size() - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (itens.at(meio).getNome() == nome) return &itens.at(meio);
        else if (itens.at(meio).getNome() < nome) esquerda = meio + 1;
        else direita = meio - 1;
    }
    return nullptr;
}

bool compararIds(const Jogador& a, const Jogador& b) {
    return a.getId() < b.getId();
}

bool compararPontuacao(const Jogador& a, const Jogador& b) {
    return (a.getPontuacao() == b.getPontuacao()) ? a.getId() < b.getId() : a.getPontuacao() > b.getPontuacao();
}

bool compararNome(const Item& a, const Item& b) {
    return a.getNome() < b.getNome();
}