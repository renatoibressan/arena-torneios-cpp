#include <string>

#include "jogador.h"
#include "../inventario/inventario.h"
#include "../item/item.h"

Jogador::Jogador(int id, std::string nome, std::string classe) : id(id), nome(nome), classe(classe), pontuacao(0), inventario(20) {
}

void Jogador::adicionarPontuacao(int valor) {
    pontuacao += valor;
}

void Jogador::removerPontuacao(int valor) {
    pontuacao -= valor;
    if (pontuacao < 0) pontuacao = 0;
}

void Jogador::inserirItem(Item item) {
    inventario.inserirItem(item);
}

void Jogador::removerItem(Item item) {
    inventario.removerItem(item.getNome());
}

void Jogador::exibirPerfil() {
}

std::string Jogador::getNome() {
    return nome;
}

int Jogador::getId() {
    return id;
}

int Jogador::getPontuacao() {
    return pontuacao;
}