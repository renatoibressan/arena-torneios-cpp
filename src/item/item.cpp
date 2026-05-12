#include <iostream>
#include <string>

#include "item.h"
#include "../tipo/tipo.h"

Item::Item(std::string nome, Tipo tipo, int raridade, int poder) : nome(nome), tipo(tipo), raridade(raridade), poder(poder) {}

void Item::exibirItem() const {
    std::cout << "------------------------------" << std::endl;
    std::cout << "Item: " << nome << std::endl;
    std::cout << "Tipo: " << tipoToString(tipo) << std::endl;
    std::cout << "Grau de raridade: " << raridade << std::endl;
    std::cout << "Poder de dano: " << poder << std::endl;
    std::cout << "------------------------------" << std::endl;
}

std::string Item::getNome() const {
    return nome;
}

int Item::getPoder() const {
    return poder;
}