#ifndef ITEM_POCAO_H
#define ITEM_POCAO_H

#include <string>

#include "item.h"

class Pocao : public Item {
    private:
        int cura;
    public:
        Pocao(std::string nome, int cura);
        void exibirItem() const override;
        void usar(Jogador& usuario, Jogador& oponente, int &vidaUsuario, int &vidaOponente) override;
        std::string serializar() const override;
        int getCura() const;
};

#endif