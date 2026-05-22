#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <cstdlib>
#include <vector>
#include <string>
#include <memory>
#include <any>

#include "../models/jogador.h"
#include "../models/item.h"

Jogador* buscarJogadorPorNome(std::vector<Jogador>& jogadores, const std::string& nome);
Jogador* buscarJogadorPorId(std::vector<Jogador>& jogadores, int id);
std::vector<std::unique_ptr<Item>>::iterator buscarItemPorNome(std::vector<std::unique_ptr<Item>>& itens, const std::string& nome);
bool compararIds(const Jogador& a, const Jogador& b);
bool compararPontuacao(const Jogador* &a, const Jogador* &b);
bool compararNomeItens(const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b);

template <typename T, class Comparador>
int particaoLomuto(std::vector<T>& vetor, int esquerda, int direita, Comparador comparar) {
    const T& pivo = vetor.at(direita);
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

template <typename T, class Comparador>
int particaoRandom(std::vector<T>& vetor, int esquerda, int direita, Comparador comparar) {
    int p = (std::rand() % (direita - esquerda + 1)) + esquerda;
    std::swap(vetor.at(p), vetor.at(direita));
    return particaoLomuto(vetor, esquerda, direita, comparar);
}

template <typename T, class Comparador>
void quickSort(std::vector<T>& vetor, int esquerda, int direita, Comparador comparar) {
    if (esquerda >= direita) return;
    int p = particaoRandom(vetor, esquerda, direita, comparar);
    quickSort(vetor, esquerda, p - 1, comparar);
    quickSort(vetor, p + 1, direita, comparar);
}

template <typename T, class Comparador>
void ordenarDados(std::vector<T>& vetor, Comparador comparar) {
    if (vetor.empty()) return;
    quickSort(vetor, 0,  vetor.size() - 1, comparar);
}

#endif