#include <string>
#include <unordered_map>

#include "categoria.h"

std::string categoriaToString(Categoria categoria) {
    switch (categoria) {
        case Categoria::Guerreiro: return "Guerreiro";
        case Categoria::Mago: return "Mago";
        case Categoria::Ladino: return "Ladino";
        case Categoria::Clerigo: return "Clerigo";
        case Categoria::Arqueiro: return "Arqueiro";
        case Categoria::Barbaro: return "Barbaro";
        case Categoria::Paladino: return "Paladino";
        case Categoria::Bardo: return "Bardo";
        case Categoria::Druida: return "Druida";
        case Categoria::Monge: return "Monge";
        default: return "";
    }
}

Categoria categoriaFromString(const std::string& categoria) {
    static const std::unordered_map<std::string, Categoria> mapa = {
        {"Guerreiro", Categoria::Guerreiro},
        {"Mago", Categoria::Mago},
        {"Ladino", Categoria::Ladino},
        {"Clerigo", Categoria::Clerigo},
        {"Arqueiro", Categoria::Arqueiro},
        {"Barbaro", Categoria::Barbaro},
        {"Paladino", Categoria::Paladino},
        {"Bardo", Categoria::Bardo},
        {"Druida", Categoria::Druida},
        {"Monge", Categoria::Monge}
    };
    auto it = mapa.find(categoria);
    if (it != mapa.end()) return it->second;
    throw "Categoria invalida!";
}