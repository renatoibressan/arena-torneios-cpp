#include <string>
#include <memory>
#include <stdexcept>

#include "item_factory.h"
#include "item_parser.h"
#include "../models/item.h"
#include "../models/item_arma.h"
#include "../models/item_pocao.h"

std::unique_ptr<Item> ItemFactory::criarItem(const DadosItem& dados, int& ultimoIdItens) {
    ultimoIdItens = std::max(ultimoIdItens, std::stoi(dados.id));
    if (dados.tipo == "Arma") return std::make_unique<Arma>(std::stoi(dados.id), dados.nome, std::stoi(dados.dano));
    if (dados.tipo == "Pocao") return std::make_unique<Pocao>(std::stoi(dados.id), dados.nome, std::stoi(dados.cura));
    throw std::invalid_argument("Tipo invalido!");
}