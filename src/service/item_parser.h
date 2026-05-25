#ifndef ITEM_PARSER_H
#define ITEM_PARSER_H

#include <string>

struct DadosItem {
    std::string id;
    std::string tipo;
    std::string nome;
    std::string dano;
    std::string cura;
};

DadosItem parseLinha(const std::string& linha);

#endif