#include <iostream>
#include <string>
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

int lerInt(const std::string& mensagem) {
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

std::string lerString(const std::string& mensagem) {
    std::cout << mensagem;
    std::string valor;
    std::getline(std::cin, valor);
    while (valor.empty()) {
        std::cout << "Leitura invalida!" << std::endl << mensagem;
        std::getline(std::cin, valor);
    }
    return valor;
}

void capitalizarString(std::string& texto) {
    if (texto.empty()) return;
    bool nextIsUpper = true;
    for (size_t i = 0; i < texto.length(); i++) {
        if (std::isspace(texto[i])) {
            nextIsUpper = true;
        } else if (nextIsUpper) {
            texto[i] = std::toupper(texto[i]);
            nextIsUpper = false;
        } else {
            texto[i] = std::tolower(texto[i]);
        }
    }
}