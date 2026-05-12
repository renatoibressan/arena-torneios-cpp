#ifndef TIPO_H
#define TIPO_H

#include <string>

enum class Tipo { Espada, Machado, Adaga, Martelo, Arco, Besta, Pistola, Rifle };

std::string tipoToString(Tipo tipo);

Tipo tipoFromString(const std::string& tipo);

#endif