#include <iostream>
#include <string>

#include "item.h"
#include "../enums/tipo.h"

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

Tipo Item::getTipo() const {
    return tipo;
}
        
int Item::getRaridade() const {
    return raridade;
}

int Item::getPoder() const {
    return poder;
}