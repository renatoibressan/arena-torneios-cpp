#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>
#include <string>

#include "../jogador/jogador.h"

bool compararPontuacao(Jogador a, Jogador b);
void ordenarRanking(std::vector<Jogador> jogadores);
Jogador* buscarJogadorPorNome(std::vector<Jogador> jogadores, std::string nome);
void troca(Jogador &a, Jogador &b);
int particaoLomuto(std::vector<Jogador> jogadores, int inicio, int fim);
int particaoRandom(std::vector<Jogador> jogadores, int inicio, int fim);
void quickSort(std::vector<Jogador> jogadores, int inicio, int fim);

#endif