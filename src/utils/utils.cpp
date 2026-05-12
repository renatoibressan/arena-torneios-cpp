#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cctype>

#include "utils.h"

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void limparBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int lerInt(std::string mensagem) {
    std::cout << mensagem;
    int valor;
    while (!(std::cin >> valor)) {
        std::cout << "Leitura invalida!" << std::endl << mensagem;
        std::cin.clear();
        limparBuffer();
    }
    limparBuffer();
    return valor;
}

std::string lerString(std::string mensagem) {
    std::cout << mensagem;
    std::string valor;
    std::getline(std::cin, valor);
    while (valor.empty()) {
        std::cout << "Leitura invalida!" << std::endl << mensagem;
        std::getline(std::cin, valor);
    }
    return valor;
}

void capitalizarString(std::string &texto) {
    if (texto.empty()) return;
    texto[0] = std::toupper(static_cast<unsigned char>(texto[0]));
    for (size_t i = 1; i < texto.length(); i++) {
        texto[i] = std::tolower(static_cast<unsigned char>(texto[i]));
    }
}