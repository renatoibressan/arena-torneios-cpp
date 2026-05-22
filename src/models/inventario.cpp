#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <memory>

#include "inventario.h"
#include "item.h"

Inventario::Inventario(int tamanhoTabela) : tamanhoTabela(tamanhoTabela), quantidadeItens(0) {
    tabela.resize(tamanhoTabela);
}

int Inventario::funcaoHash(std::string chave) {
    int hash = 0;
    for (char c : chave) hash += c;
    return hash % tamanhoTabela;
}

void Inventario::inserirItem(std::unique_ptr<Item> item) {
    int idx = funcaoHash(item->getNome());
    tabela.at(idx).push_back(std::move(item));
    quantidadeItens++;
}

std::unique_ptr<Item> Inventario::removerItem(const std::string& nome) {
    int idx = funcaoHash(nome);
    auto& bucket = tabela.at(idx);
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if ((*it)->getNome() == nome) {
            std::unique_ptr<Item> itemRemovido = std::move(*it);
            bucket.erase(it);
            quantidadeItens--;
            return itemRemovido;
        }
    }
    return nullptr;
}

Item* Inventario::buscarItem(const std::string& nome) {
    int idx = funcaoHash(nome);
    for (auto& item : tabela.at(idx)) if (item->getNome() == nome) return item.get();
    return nullptr;
}

void Inventario::listarItens() const {
    for (const auto& bucket : tabela) {
        for (const auto& item : bucket) item->exibirItem();
    }
}

void Inventario::listarItensBatalha() const {
    std::cout << "---------------------------------------------" << std::endl;
    int idx = 1;
    for (const auto& bucket : tabela) {
        for (const auto& item : bucket) {
            std::cout << idx++ << ". " << item->getNome() << std::endl;
        }
    }
    std::cout << "---------------------------------------------" << std::endl;
}

bool Inventario::inventarioVazio() const {
    return quantidadeItens == 0;
}

std::vector<std::unique_ptr<Item>> Inventario::extrairItens() {
    std::vector<std::unique_ptr<Item>> itensExtraidos;
    for (auto& bucket : tabela) {
        for (auto& item : bucket) {
            itensExtraidos.push_back(std::move(item));
        }
        bucket.clear();
    }
    quantidadeItens = 0;
    return itensExtraidos;
}