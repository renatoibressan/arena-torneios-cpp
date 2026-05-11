#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <list>
#include <string>

#include "item.h"

class Inventario {
    private:
        std::vector<std::list<Item>> tabela;
    public:
        int funcaoHash(std::string chave);
        void inserirItem(Item item);
        bool removerItem(std::string nome);
        Item* buscarItem(std::string nome);
        void listarItens();
};

#endif