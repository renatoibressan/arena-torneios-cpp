#include <string>

#include "item.h"

Item::Item(std::string nome, std::string tipo, int raridade, int poder) : nome(nome), tipo(tipo), raridade(raridade), poder(poder) {}

void Item::exibirItem() {
}

std::string Item::getNome() {
    return nome;
}