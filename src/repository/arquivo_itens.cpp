#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <filesystem>

#include "arquivo_itens.h"
#include "../models/item.h"
#include "../enums/tipo.h"

ArquivoItens::ArquivoItens(const std::string& caminho) : caminho(caminho) {}

bool ArquivoItens::salvarItens(const std::vector<Item>& itens) const {
    std::ofstream arquivo(caminho);
    if (!arquivo.is_open()) return false;
    arquivo << "nome,tipo,raridade,poder\n";
    for (const Item& item : itens) {
        arquivo << item.getNome() << ","
                << tipoToString(item.getTipo()) << ","
                << item.getRaridade() << ","
                << item.getPoder() << "\n";
    }
    return true;
}

bool ArquivoItens::carregarItens(std::vector<Item>& itens) const {
    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) return false;
    std::string linha;
    std::getline(arquivo, linha);
    while (std::getline(arquivo, linha)) {
        try {
            std::stringstream ss(linha);
            std::string nome;
            std::getline(ss, nome, ',');
            std::string tipoStr;
            std::getline(ss, tipoStr, ',');
            Tipo tipo = tipoFromString(tipoStr);
            std::string raridadeStr;
            std::getline(ss, raridadeStr, ',');
            int raridade = std::stoi(raridadeStr);
            std::string poderStr;
            std::getline(ss, poderStr, ',');
            int poder = std::stoi(poderStr);
            itens.emplace_back(nome, tipo, raridade, poder);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Erro ao ler linha " << linha << ": " << e.what() <<std::endl;
        }
    }
    return true;
}

bool ArquivoItens::arquivoExiste() const {
    return std::filesystem::exists(caminho);
}