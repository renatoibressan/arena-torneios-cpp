#include <iostream>
#include <string>

#include "item.h"

Item::Item(std::string nome, std::string tipo, int raridade, int poder) : nome(nome), tipo(tipo), raridade(raridade), poder(poder) {}

void Item::exibirItem() {
    std::cout << "------------------------------" << std::endl;
    std::cout << "Item: " << nome << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Grau de raridade: " << raridade << std::endl;
    std::cout << "Poder de dano: " << poder << std::endl;
    std::cout << "------------------------------" << std::endl;
}

std::string Item::getNome() {
    return nome;
}