#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <filesystem>

#include "arquivo.h"
#include "../models/jogador.h"
#include "../enums/categoria.h"

Arquivo::Arquivo(const std::string& caminho) : caminho(caminho) {}

bool Arquivo::salvarJogadores(const std::vector<Jogador>& jogadores) const {
    std::ofstream arquivo(caminho);
    if (!arquivo.is_open()) return false;
    arquivo << "id,nome,categoria,vida,pontuacao\n";
    for (const Jogador& jogador : jogadores) {
        arquivo << jogador.getId() << "," 
                << jogador.getNome() << "," 
                << categoriaToString(jogador.getCategoria()) << "," 
                << jogador.getVida() << ","
                << jogador.getPontuacao() << "\n";
    }
    return true;
}

bool Arquivo::carregarJogadores(std::vector<Jogador>& jogadores, int& ultimoId) const {
    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) return false;
    std::string linha;
    ultimoId = 0;
    std::getline(arquivo, linha);
    while (std::getline(arquivo, linha)) {
        try {
            std::stringstream ss(linha);
            std::string idStr;
            std::getline(ss, idStr, ',');
            int id = std::stoi(idStr);
            std::string nome;
            std::getline(ss, nome, ',');
            std::string categoriaStr;
            std::getline(ss, categoriaStr, ',');
            Categoria categoria = categoriaFromString(categoriaStr);
            std::string vidaStr;
            std::getline(ss, vidaStr, ',');
            int vida = std::stoi(vidaStr);
            std::string pontuacaoStr;
            std::getline(ss, pontuacaoStr, ',');
            int pontuacao = std::stoi(pontuacaoStr);
            Jogador jogador = Jogador(id, nome, categoria, vida);
            jogador.setPontuacao(pontuacao);
            jogadores.push_back(jogador);
            ultimoId = std::max(ultimoId, id);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Erro ao ler linha " << linha << ": " << e.what() <<std::endl;
        }
    }
    return true;
}

bool Arquivo::arquivoExiste() const {
    return std::filesystem::exists(caminho);
}