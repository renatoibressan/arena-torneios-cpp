#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>
#include <string>

#include "../models/jogador.h"

Jogador* buscarJogadorPorNome(std::vector<Jogador>& jogadores, const std::string nome);
Jogador* buscarJogadorPorId(std::vector<Jogador>& jogadores, int id);
bool compararIds(const Jogador& a, const Jogador& b);
bool compararPontuacao(const Jogador& a, const Jogador& b);
int particaoLomuto(std::vector<Jogador>& jogadores, int inicio, int fim, bool (*comparar)(const Jogador&, const Jogador&));
int particaoRandom(std::vector<Jogador>& jogadores, int inicio, int fim, bool (*comparar)(const Jogador&, const Jogador&));
void quickSort(std::vector<Jogador>& jogadores, int inicio, int fim, bool (*comparar)(const Jogador&, const Jogador&));
void ordenarJogadores(std::vector<Jogador>& jogadores, bool (*comparar)(const Jogador&, const Jogador&));

#endif