#include <vector>
#include <string>
#include <cstdlib>

#include "algoritmos.h"
#include "../jogador/jogador.h"

Jogador* buscarJogadorPorNome(std::vector<Jogador>& jogadores, const std::string nome) {
    for (Jogador& jogador : jogadores) if (jogador.getNome() == nome) return &jogador;
    return nullptr;
}

Jogador* buscarJogadorPorId(std::vector<Jogador>& jogadores, int id) {
    for (Jogador& jogador: jogadores) if (jogador.getId() == id) return &jogador;
    return nullptr;
}

bool compararPontuacao(const Jogador& a, const Jogador& b) {
    return a.getPontuacao() >= b.getPontuacao();
}

void troca(Jogador &a, Jogador &b) {
    Jogador temp = a;
    a = b;
    b = temp;
}

int particaoLomuto(std::vector<Jogador>& jogadores, int inicio, int fim) {
    Jogador pivo = jogadores.at(fim);
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (!compararPontuacao(jogadores.at(j), pivo)) {
            i++;
            troca(jogadores.at(i), jogadores.at(j));
        }
    }
    troca(jogadores.at(i + 1), jogadores.at(fim));
    return i + 1;
}

int particaoRandom(std::vector<Jogador>& jogadores, int inicio, int fim) {
    int p = (std::rand() % (fim - inicio + 1)) + inicio;
    troca(jogadores.at(p), jogadores.at(fim));
    return particaoLomuto(jogadores, inicio, fim);
}

void quickSort(std::vector<Jogador>& jogadores, int inicio, int fim) {
    if (inicio < fim) {
        int p = particaoRandom(jogadores, inicio, fim);
        quickSort(jogadores, inicio, p - 1);
        quickSort(jogadores, p + 1, fim);
    }
}

void ordenarRanking(std::vector<Jogador>& jogadores) {
    quickSort(jogadores, 0,  jogadores.size() - 1);
}