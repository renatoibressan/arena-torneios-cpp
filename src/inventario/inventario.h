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
        int quantidadeItens;
    public:
        Inventario(int tamanhoTabela);
        int funcaoHash(std::string chave);
        void inserirItem(const Item& item);
        bool removerItem(const std::string& nome);
        Item* buscarItem(const std::string& nome);
        void listarItens() const;
        void listarItensBatalha() const;
        bool inventarioVazio() const;
};

#endif