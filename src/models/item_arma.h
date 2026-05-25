#ifndef ITEM_ARMA_H
#define ITEM_ARMA_H

#include <string>

#include "item.h"

class Arma : public Item {
    private:
        int dano;
    public:
        Arma(int id, std::string nome, int dano);
        void exibirItem() const override;
        void usar(Jogador& usuario, Jogador& oponente, int &vidaUsuario, int &vidaOponente) override;
        std::string serializar() const override;
        int getDano() const;
};

#endif