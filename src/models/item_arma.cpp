#include <iostream>
#include <string>

#include "item_arma.h"
#include "item.h"
#include "jogador.h"
#include "../enums/tipo.h"

Arma::Arma(std::string nome, int dano) : Item(nome, Tipo::Arma), dano(dano) {}

void Arma::exibirItem() const {
    std::cout << "------------------------------" << std::endl;
    std::cout << "Item: " << nome << std::endl;
    std::cout << "Tipo: " << tipoToString(Tipo::Arma) << std::endl;
    std::cout << "Dano: " << dano << std::endl;
    std::cout << "------------------------------" << std::endl;
}

void Arma::usar(Jogador& usuario, Jogador& oponente, int &vidaUsuario, int &vidaOponente) {
    int efeito = dano / 10;
    vidaOponente -= efeito;
    if (vidaOponente < 0) vidaOponente = 0;
    (efeito != 0) ? std::cout << std::endl << oponente.getNome() << " perdeu " << efeito << " pontos de vida!" << std::endl
                        : std::cout << std::endl << nome << " nao fez efeito em " << oponente.getNome() << "!" << std::endl;
}

std::string Arma::serializar() const {
    return "Arma," + nome + "," + std::to_string(dano) + ",";
}

int Arma::getDano() const {
    return dano;
}