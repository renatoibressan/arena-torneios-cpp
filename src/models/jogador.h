#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

#include "inventario.h"
#include "item.h"
#include "../enums/categoria.h"

class Jogador {
    private:
        int id;
        std::string nome;
        Categoria categoria;
        int vida;
        int pontuacao;
        Inventario inventario;
    public:
        Jogador(int id, const std::string& nome, Categoria categoria, int vida);
        void adicionarPontuacao(int valor);
        void removerPontuacao(int valor);
        void inserirItem(const Item& item);
        bool removerItem(const std::string& nome);
        Item* buscarItem(const std::string& nome);
        void listarItens() const;
        void listarItensBatalha() const;
        bool inventarioVazio() const;
        void exibirPerfil() const;
        int getId() const;
        const std::string& getNome() const;
        Categoria getCategoria() const;
        int getVida() const;
        int getPontuacao() const;
        void setPontuacao(int pontuacao);
};

#endif