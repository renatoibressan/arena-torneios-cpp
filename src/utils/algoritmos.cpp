#include <cstdlib>
#include <vector>
#include <string>

#include "algoritmos.h"
#include "../models/jogador.h"

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

bool compararIds(const Jogador& a, const Jogador& b) {
    return a.getId() < b.getId();
}

bool compararPontuacao(const Jogador& a, const Jogador& b) {
    return (a.getPontuacao() == b.getPontuacao()) ? a.getId() < b.getId() : a.getPontuacao() > b.getPontuacao();
}

int particaoLomuto(std::vector<Jogador>& jogadores, int esquerda, int direita, bool (*comparar)(const Jogador&, const Jogador&)) {
    Jogador pivo = jogadores.at(direita);
    int i = esquerda - 1;
    for (int j = esquerda; j < direita; j++) {
        if (comparar(jogadores.at(j), pivo)) {
            i++;
            std::swap(jogadores.at(i), jogadores.at(j));
        }
    }
    std::swap(jogadores.at(i + 1), jogadores.at(direita));
    return i + 1;
}

int particaoRandom(std::vector<Jogador>& jogadores, int esquerda, int direita, bool (*comparar)(const Jogador&, const Jogador&)) {
    int p = (std::rand() % (direita - esquerda + 1)) + esquerda;
    std::swap(jogadores.at(p), jogadores.at(direita));
    return particaoLomuto(jogadores, esquerda, direita, comparar);
}

void quickSort(std::vector<Jogador>& jogadores, int esquerda, int direita, bool (*comparar)(const Jogador&, const Jogador&)) {
    if (esquerda >= direita) return;
    int p = particaoRandom(jogadores, esquerda, direita, comparar);
    quickSort(jogadores, esquerda, p - 1, comparar);
    quickSort(jogadores, p + 1, direita, comparar);
}

void ordenarJogadores(std::vector<Jogador>& jogadores, bool (*comparar)(const Jogador&, const Jogador&)) {
    if (jogadores.empty()) return;
    quickSort(jogadores, 0,  jogadores.size() - 1, comparar);
}