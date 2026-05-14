#include <iostream>
#include <string>
#include <algorithm>

#include "jogador.h"
#include "../categoria/categoria.h"
#include "../inventario/inventario.h"
#include "../item/item.h"

Jogador::Jogador(int id, const std::string& nome, Categoria categoria, int vida) : id(id), nome(nome), categoria(categoria), vida(vida), pontuacao(0), inventario(4) {}

void Jogador::adicionarPontuacao(int valor) {
    pontuacao += valor;
}

void Jogador::removerPontuacao(int valor) {
    pontuacao = std::max(0, pontuacao - valor);
}

void Jogador::inserirItem(const Item& item) {
    inventario.inserirItem(item);
}

bool Jogador::removerItem(const std::string& nome) {
    return inventario.removerItem(nome);
}

Item* Jogador::buscarItem(const std::string& nome) {
    return inventario.buscarItem(nome);
}

void Jogador::listarItens() const {
    inventario.listarItens();
}

void Jogador::listarItensBatalha() const {
    inventario.listarItensBatalha();
}

void Jogador::exibirPerfil() const {
    std::cout << "------------------------------" << std::endl;
    std::cout << "Jogador #" << id << ": " << nome << std::endl;
    std::cout << "Categoria: " << categoriaToString(categoria) << std::endl;
    std::cout << "Pontuacao atual: " << pontuacao << std::endl;
    std::cout << "Vida total: " << vida << std::endl;
    std::cout << "------------------------------" << std::endl;
}

const std::string& Jogador::getNome() const {
    return nome;
}

int Jogador::getId() const {
    return id;
}

int Jogador::getVida() const {
    return vida;
}

int Jogador::getPontuacao() const {
    return pontuacao;
}