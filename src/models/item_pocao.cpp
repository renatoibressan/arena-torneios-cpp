#include <iostream>
#include <string>

#include "item_pocao.h"
#include "item.h"
#include "jogador.h"
#include "../enums/tipo.h"

Pocao::Pocao(int id, std::string nome, int cura) : Item(id, nome, Tipo::Pocao), cura(cura) {}

void Pocao::exibirItem() const {
    std::cout << "------------------------------" << std::endl;
    std::cout << "Item: " << nome << std::endl;
    std::cout << "Tipo: " << tipoToString(Tipo::Pocao) << std::endl;
    std::cout << "Cura: " << cura << std::endl;
    std::cout << "------------------------------" << std::endl;
}

void Pocao::usar(Jogador& usuario, Jogador& oponente, int &vidaUsuario, int &vidaOponente) {
    int efeito = cura / 10;
    vidaUsuario += efeito;
    if (vidaUsuario > usuario.getVida()) vidaUsuario = usuario.getVida();
    (efeito != usuario.getVida()) ? std::cout << std::endl << usuario.getNome() << " recuperou " << efeito << " pontos de vida!" << std::endl 
                                    : std::cout << std::endl << usuario.getNome() << " ja esta com a vida cheia!" << std::endl;
}

std::string Pocao::serializar() const {
    return std::to_string(id) + ",Pocao," + nome + ",," + std::to_string(cura);
}

int Pocao::getCura() const {
    return cura;
}