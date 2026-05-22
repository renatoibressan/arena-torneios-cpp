#include <iostream>
#include <string>

#include "item.h"
#include "../enums/tipo.h"

Item::Item(std::string nome, Tipo tipo) : nome(nome), tipo(tipo) {}

std::string Item::getNome() const {
    return nome;
}

Tipo Item::getTipo() const {
    return tipo;
}