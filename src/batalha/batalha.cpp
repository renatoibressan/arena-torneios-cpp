#include "batalha.h"

int calcularDano(int dano) {
    return dano / 10;
}

int calcularVidaPerdida(int vida, int dano) {
    return (vida <= dano) ? vida : dano;
}

int calcularVidaAtual(int vida, int dano) {
    return (vida <= dano) ? 0 : vida - dano;
}