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
    for (Jogador& jogador: jogadores) if (jogador.getId() == id) return &jogador;
    return nullptr;
}

bool compararIds(const Jogador& a, const Jogador& b) {
    return a.getId() < b.getId();
}

bool compararPontuacao(const Jogador& a, const Jogador& b) {
    return (a.getPontuacao() == b.getPontuacao()) ? a.getId() < b.getId() : a.getPontuacao() > b.getPontuacao();
}

int particaoLomuto(std::vector<Jogador>& jogadores, int inicio, int fim, bool (*comparar)(const Jogador&, const Jogador&)) {
    Jogador pivo = jogadores.at(fim);
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (comparar(jogadores.at(j), pivo)) {
            i++;
            std::swap(jogadores.at(i), jogadores.at(j));
        }
    }
    std::swap(jogadores.at(i + 1), jogadores.at(fim));
    return i + 1;
}

int particaoRandom(std::vector<Jogador>& jogadores, int inicio, int fim, bool (*comparar)(const Jogador&, const Jogador&)) {
    int p = (std::rand() % (fim - inicio + 1)) + inicio;
    std::swap(jogadores.at(p), jogadores.at(fim));
    return particaoLomuto(jogadores, inicio, fim, comparar);
}

void quickSort(std::vector<Jogador>& jogadores, int inicio, int fim, bool (*comparar)(const Jogador&, const Jogador&)) {
    if (inicio >= fim) return;
    int p = particaoRandom(jogadores, inicio, fim, comparar);
    quickSort(jogadores, inicio, p - 1, comparar);
    quickSort(jogadores, p + 1, fim, comparar);
}

void ordenarJogadores(std::vector<Jogador>& jogadores, bool (*comparar)(const Jogador&, const Jogador&)) {
    if (jogadores.empty()) return;
    quickSort(jogadores, 0,  jogadores.size() - 1, comparar);
}