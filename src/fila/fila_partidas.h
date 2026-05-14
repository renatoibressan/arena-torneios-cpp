#ifndef FILA_PARTIDAS_H
#define FILA_PARTIDAS_H

#include <queue>
#include <string>

class FilaPartidas {
    private:
        std::queue<int> fila;
    public:
        void enfileirar(int id);
        int desenfileirar();
        void mostrarFila(const std::string& mensagem);
        bool filaVazia() const;
};

#endif