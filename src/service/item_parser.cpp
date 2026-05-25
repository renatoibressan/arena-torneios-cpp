#include <string>
#include <sstream>

#include "item_parser.h"

DadosItem parseLinha(const std::string& linha) {
    std::stringstream ss(linha);
    DadosItem dados;
    std::getline(ss, dados.id, ',');
    std::getline(ss, dados.tipo, ',');
    std::getline(ss, dados.nome, ',');
    std::getline(ss, dados.dano, ',');
    std::getline(ss, dados.cura, ',');
    return dados;
}