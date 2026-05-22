#ifndef TIPO_H
#define TIPO_H

#include <string>

enum class Tipo { Arma, Pocao };

std::string tipoToString(Tipo tipo);

Tipo tipoFromString(const std::string& tipo);

#endif