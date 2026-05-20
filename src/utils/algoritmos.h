#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <cstdlib>
#include <vector>
#include <string>
#include <any>

#include "../models/jogador.h"
#include "../models/item.h"

Jogador* buscarJogadorPorNome(std::vector<Jogador>& jogadores, const std::string nome);
Jogador* buscarJogadorPorId(std::vector<Jogador>& jogadores, int id);
Item* buscarItemPorNome(std::vector<Item>& itens, const std::string nome);
bool compararIds(const Jogador& a, const Jogador& b);
bool compararPontuacao(const Jogador& a, const Jogador& b);
bool compararNome(const Item& a, const Item& b);

template <typename T>
int particaoLomuto(std::vector<T>& vetor, int esquerda, int direita, bool (*comparar)(const T&, const T&)) {
    T pivo = vetor.at(direita);
    int i = esquerda - 1;
    for (int j = esquerda; j < direita; j++) {
        if (comparar(vetor.at(j), pivo)) {
            i++;
            std::swap(vetor.at(i), vetor.at(j));
        }
    }
    std::swap(vetor.at(i + 1), vetor.at(direita));
    return i + 1;
}

template <typename T>
int particaoRandom(std::vector<T>& vetor, int esquerda, int direita, bool (*comparar)(const T&, const T&)) {
    int p = (std::rand() % (direita - esquerda + 1)) + esquerda;
    std::swap(vetor.at(p), vetor.at(direita));
    return particaoLomuto(vetor, esquerda, direita, comparar);
}

template <typename T>
void quickSort(std::vector<T>& vetor, int esquerda, int direita, bool (*comparar)(const T&, const T&)) {
    if (esquerda >= direita) return;
    int p = particaoRandom(vetor, esquerda, direita, comparar);
    quickSort(vetor, esquerda, p - 1, comparar);
    quickSort(vetor, p + 1, direita, comparar);
}

template <typename T>
void ordenarDados(std::vector<T>& vetor, bool (*comparar)(const T&, const T&)) {
    if (vetor.empty()) return;
    quickSort(vetor, 0,  vetor.size() - 1, comparar);
}

#endif