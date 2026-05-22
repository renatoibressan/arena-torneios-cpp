#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <list>
#include <string>
#include <memory>

#include "item.h"

class Inventario {
    private:
        std::vector<std::list<std::unique_ptr<Item>>> tabela;
        int tamanhoTabela;
        int quantidadeItens;
    public:
        Inventario(int tamanhoTabela);
        int funcaoHash(std::string chave);
        void inserirItem(std::unique_ptr<Item> item);
        std::unique_ptr<Item> removerItem(const std::string& nome);
        Item* buscarItem(const std::string& nome);
        void listarItens() const;
        void listarItensBatalha() const;
        bool inventarioVazio() const;
        std::vector<std::unique_ptr<Item>> extrairItens();
};

#endif