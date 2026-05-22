#include <iostream>
#include <cstdlib>
#include <string>

#include "sistema_partidas.h"
#include "../models/jogador.h"
#include "../utils/utils.h"

ResultadoPartida executarPartida(Jogador *j1, Jogador *j2) {
    Jogador *primeiro = (std::rand() % 2 == 0) ? j1 : j2;
    Jogador *segundo = (primeiro == j1) ? j2 : j1;
    int vidaJ1 = primeiro->getVida();
    int vidaJ2 = segundo->getVida();
    int turnos = 0;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Partida entre " << primeiro->getNome() << " e " << segundo->getNome() << " iniciada!" << std::endl;
    while (true) {
        turnos++;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << primeiro->getNome() << " (" << vidaJ1 << " / " << primeiro->getVida() << ")" << std::endl;
        std::cout << segundo->getNome() << " (" << vidaJ2 << " / " << segundo->getVida() << ")" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        primeiro->listarItensBatalha();
        std::string nomeItem1 = lerString("Insira o nome do item do primeiro para busca: ");
        capitalizarString(nomeItem1);
        Item *itemJ1 = primeiro->buscarItem(nomeItem1);
        while (!itemJ1) {
            std::cout << "Item " << nomeItem1 << " nao encontrado, tente novamente!" << std::endl;
            nomeItem1 = lerString("Insira o nome do item do primeiro para busca: ");
            capitalizarString(nomeItem1);
            itemJ1 = primeiro->buscarItem(nomeItem1);
        }
        segundo->listarItensBatalha();
        std::string nomeItem2 = lerString("Insira o nome do item do segundo para busca: ");
        capitalizarString(nomeItem2);
        Item *itemJ2 = segundo->buscarItem(nomeItem2);
        while (!itemJ2) {
            std::cout << "Item " << nomeItem2 << " nao encontrado, tente novamente!" << std::endl;
            nomeItem2 = lerString("Insira o nome do item do segundo para busca: ");
            capitalizarString(nomeItem2);
            itemJ2 = primeiro->buscarItem(nomeItem2);
        }
        itemJ1->usar(*primeiro, *segundo, vidaJ1, vidaJ2);
        if (vidaJ2 <= 0) {
            std::cout << std::endl << segundo->getNome() << " foi nocauteado em  " << turnos << " turnos!" << std::endl;
            std::cout << primeiro->getNome() << " foi o vencedor da partida!" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            return {primeiro->getId(), segundo->getId(), turnos};
        }
        itemJ2->usar(*segundo, *primeiro, vidaJ2, vidaJ1);
        if (vidaJ1 <= 0) {
            std::cout << std::endl << primeiro->getNome() << " foi nocauteado em " << turnos << " turnos!" << std::endl;
            std::cout << segundo->getNome() << " foi o vencedor da partida!" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            return {segundo->getId(), primeiro->getId(), turnos};
        }
    }
}