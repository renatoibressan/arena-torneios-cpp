#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

#include "../categoria/categoria.h"
#include "../inventario/inventario.h"
#include "../item/item.h"

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
        const std::string& getNome() const;
        int getId() const;
        int getVida() const;
        int getPontuacao() const;
};

#endif