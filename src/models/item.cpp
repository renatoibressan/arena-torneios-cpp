#include <iostream>
#include <string>

#include "item.h"
#include "../enums/tipo.h"

Item::Item(int id, std::string nome, Tipo tipo) : id(id), nome(nome), tipo(tipo) {}

int Item::getId() const {
    return id;
}

std::string Item::getNome() const {
    return nome;
}

Tipo Item::getTipo() const {
    return tipo;
}