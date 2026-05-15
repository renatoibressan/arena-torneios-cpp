#include <string>
#include <unordered_map>
#include <stdexcept>

#include "tipo.h"

std::string tipoToString(Tipo tipo) {
    switch (tipo) {
        case Tipo::Espada: return "Espada";
        case Tipo::Machado: return "Machado";
        case Tipo::Adaga: return "Adaga";
        case Tipo::Martelo: return "Martelo";
        case Tipo::Arco: return "Arco";
        case Tipo::Besta: return "Besta";
        case Tipo::Pistola: return "Pistola";
        case Tipo::Rifle: return "Rifle";
        default: return "";
    }
}

Tipo tipoFromString(const std::string& tipo) {
    static const std::unordered_map<std::string, Tipo> mapa = {
        {"Espada", Tipo::Espada},
        {"Machado", Tipo::Machado},
        {"Adaga", Tipo::Adaga},
        {"Martelo", Tipo::Martelo},
        {"Arco", Tipo::Arco},
        {"Besta", Tipo::Besta},
        {"Pistola", Tipo::Pistola},
        {"Rifle", Tipo::Rifle}
    };
    auto it = mapa.find(tipo);
    if (it != mapa.end()) return it->second;
    throw std::invalid_argument("Tipo invalido!");
}