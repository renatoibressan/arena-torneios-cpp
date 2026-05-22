#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

#include "jogador.h"
#include "inventario.h"
#include "item.h"
#include "../enums/categoria.h"

Jogador::Jogador(int id, const std::string& nome, Categoria categoria, int vida) : id(id), nome(nome), categoria(categoria), vida(vida), pontuacao(0), inventario(10) {}

void Jogador::adicionarPontuacao(int valor) {
    pontuacao += valor;
}

void Jogador::removerPontuacao(int valor) {
    pontuacao = std::max(0, pontuacao - valor);
}

void Jogador::inserirItem(std::unique_ptr<Item> item) {
    inventario.inserirItem(std::move(item));
}

std::unique_ptr<Item> Jogador::removerItem(const std::string& nome) {
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

bool Jogador::inventarioVazio() const {
    return inventario.inventarioVazio();
}

std::vector<std::unique_ptr<Item>> Jogador::extrairItens() {
    return inventario.extrairItens();
}

void Jogador::exibirPerfil() const {
    std::cout << "------------------------------" << std::endl;
    std::cout << "Jogador #" << id << ": " << nome << std::endl;
    std::cout << "Categoria: " << categoriaToString(categoria) << std::endl;
    std::cout << "Vida total: " << vida << std::endl;
    std::cout << "Pontuacao atual: " << pontuacao << std::endl;
    std::cout << "------------------------------" << std::endl;
}

int Jogador::getId() const {
    return id;
}

const std::string& Jogador::getNome() const {
    return nome;
}

Categoria Jogador::getCategoria() const {
    return categoria;
}

int Jogador::getVida() const {
    return vida;
}

int Jogador::getPontuacao() const {
    return pontuacao;
}

void Jogador::setPontuacao(int pontuacao) {
    this->pontuacao = pontuacao;
}