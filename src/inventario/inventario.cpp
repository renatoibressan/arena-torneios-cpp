#include <list>
#include <string>

#include "inventario.h"
#include "../item/item.h"

Inventario::Inventario(int tamanhoTabela) : tamanhoTabela(tamanhoTabela) {}

int Inventario::funcaoHash(std::string chave) {
    int hash = 0;
    for (char c : chave) hash += c;
    return hash % tamanhoTabela;
}

void Inventario::inserirItem(Item item) {
}

void Inventario::removerItem(std::string nome) {
}

Item* Inventario::buscarItem(std::string nome) {
}

void Inventario::listarItens() {
    if (tabela.empty()) return;
    for (int i = 0; i < tamanhoTabela; i++) {
        std::list<Item> itens = tabela.at(i);
        for (Item item : itens) item.exibirItem();
    }
}