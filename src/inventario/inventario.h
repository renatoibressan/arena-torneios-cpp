#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <list>
#include <string>

#include "../item/item.h"

class Inventario {
    private:
        std::vector<std::list<Item>> tabela;
        int tamanhoTabela;
    public:
        Inventario(int tamanhoTabela);
        int funcaoHash(std::string chave);
        void inserirItem(Item item);
        void removerItem(std::string nome);
        Item* buscarItem(std::string nome);
        void listarItens();
};

#endif