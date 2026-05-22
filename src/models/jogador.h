#ifndef JOGADOR_H
#define JOGADOR_H

#include <vector>
#include <string>
#include <memory>

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
        void inserirItem(std::unique_ptr<Item> item);
        std::unique_ptr<Item> removerItem(const std::string& nome);
        Item* buscarItem(const std::string& nome);
        void listarItens() const;
        void listarItensBatalha() const;
        bool inventarioVazio() const;
        std::vector<std::unique_ptr<Item>> extrairItens();
        void exibirPerfil() const;
        int getId() const;
        const std::string& getNome() const;
        Categoria getCategoria() const;
        int getVida() const;
        int getPontuacao() const;
        void setPontuacao(int pontuacao);
};

#endif