#pragma once

#include <string>

#include "../enums/tipo.h"

class Jogador;

class Item {
    protected:
        std::string nome;
        Tipo tipo;
    public:
        Item(std::string nome, Tipo tipo);
        virtual ~Item() = default;
        virtual void exibirItem() const = 0;
        virtual void usar(Jogador& usuario, Jogador& oponente, int &vidaUsuario, int &vidaOponente) = 0;
        virtual std::string serializar() const = 0;
        std::string getNome() const;
        Tipo getTipo() const;
};