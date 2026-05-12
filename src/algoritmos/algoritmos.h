#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>
#include <string>

#include "../jogador/jogador.h"

Jogador* buscarJogadorPorNome(std::vector<Jogador>& jogadores, const std::string nome);
bool compararPontuacao(const Jogador& a, const Jogador& b);
void troca(Jogador &a, Jogador &b);
int particaoLomuto(std::vector<Jogador>& jogadores, int inicio, int fim);
int particaoRandom(std::vector<Jogador>& jogadores, int inicio, int fim);
void quickSort(std::vector<Jogador>& jogadores, int inicio, int fim);
void ordenarRanking(std::vector<Jogador>& jogadores);

#endif