#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <string>
#include <vector>

#include "jogador.h"

bool compararPontuacao(Jogador a, Jogador b);
void ordenarRanking();
Jogador* buscarJogadorPorNome(std::string nome);
Jogador* buscarJogadorPorId(int id);
void troca(Jogador *a, Jogador *b);
int particaoLomuto(std::vector<Jogador> jogadores, int inicio, int fim);
int particaoRandom(std::vector<Jogador> jogadores, int inicio, int fim);
void quickSort(std::vector<Jogador> jogadores, int inicio, int fim);

#endif