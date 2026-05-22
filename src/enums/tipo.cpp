#include <string>
#include <unordered_map>
#include <stdexcept>

#include "tipo.h"

std::string tipoToString(Tipo tipo) {
    switch (tipo) {
        case Tipo::Arma: return "Arma";
        case Tipo::Pocao: return "Pocao";
        default: return "";
    }
}

Tipo tipoFromString(const std::string& tipo) {
    static const std::unordered_map<std::string, Tipo> mapa = {
        {"Arma", Tipo::Arma},
        {"Pocao", Tipo::Pocao}
    };
    auto it = mapa.find(tipo);
    if (it != mapa.end()) return it->second;
    throw std::invalid_argument("Tipo invalido!");
}