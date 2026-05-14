#include <iostream>
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

void Inventario::inserirItem(const Item& item) {
    int idx = funcaoHash(item.getNome());
    tabela.at(idx).push_back(item);
}

bool Inventario::removerItem(const std::string& nome) {
    int idx = funcaoHash(nome);
    auto& bucket = tabela.at(idx);
    for (auto i = bucket.begin(); i != bucket.end(); ++i) {
        if (i->getNome() == nome) {
            bucket.erase(i);
            return true;
        }
    }
    return false;
}

Item* Inventario::buscarItem(const std::string& nome) {
    int idx = funcaoHash(nome);
    for (Item& item : tabela.at(idx)) if (item.getNome() == nome) return &item;
    return nullptr;
}

void Inventario::listarItens() const {
    for (size_t i = 0; i < tabela.size(); i++) {
        const auto& itens = tabela.at(i);
        for (const Item& item : itens) item.exibirItem();
    }
}

void Inventario::listarItensBatalha() const {
    std::cout << "---------------------------------------------" << std::endl;
    int idx = 1;
    for (auto& bucket : tabela) {
        for (auto& item : bucket) {
            std::cout << idx++ << ". " << item.getNome() << " (Pow. " << item.getPoder() << ")" << std::endl;
        }
    }
    std::cout << "---------------------------------------------" << std::endl;
}