#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
    private:
        std::string nome;
        std::string tipo;
        int raridade;
        int poder;
    public:
        Item(std::string nome, std::string tipo, int raridade, int poder);
        void exibirItem();
        std::string getNome();
};

#endif