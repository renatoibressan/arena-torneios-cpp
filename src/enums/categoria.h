#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

enum class Categoria { Guerreiro, Mago, Ladino, Clerigo, Arqueiro, Barbaro, Paladino, Bardo, Druida, Monge };

std::string categoriaToString(Categoria categoria);

Categoria categoriaFromString(const std::string& categoria);

#endif