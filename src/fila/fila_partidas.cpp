#include <iostream>
#include <string>

#include "fila_partidas.h"

void FilaPartidas::enfileirar(int id) {
    fila.push(id);
}

int FilaPartidas::desenfileirar() {
    if (filaVazia()) return -1;
    int id = fila.front();
    fila.pop();
    return id;
}

void FilaPartidas::mostrarFila(const std::string& mensagem) {
    std::cout << mensagem << std::endl;
    std::queue<int> temp = fila;
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

bool FilaPartidas::filaVazia() const {
    return fila.empty();
}

int FilaPartidas::tamanhoFila() const {
    return fila.size();
}