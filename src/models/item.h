#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "../enums/tipo.h"

class Item {
    private:
        std::string nome;
        Tipo tipo;
        int raridade;
        int poder;
    public:
        Item(std::string nome, Tipo tipo, int raridade, int poder);
        void exibirItem() const;
        std::string getNome() const;
        Tipo getTipo() const;
        int getRaridade() const;
        int getPoder() const;
};

#endif