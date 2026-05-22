#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <stdexcept>
#include <filesystem>

#include "arquivo_itens.h"
#include "../models/item.h"
#include "../service/item_parser.h"
#include "../service/item_factory.h"

ArquivoItens::ArquivoItens(const std::string& caminho) : caminho(caminho) {}

bool ArquivoItens::salvarItens(const std::vector<std::unique_ptr<Item>>& itens) const {
    std::ofstream arquivo(caminho);
    if (!arquivo.is_open()) return false;
    arquivo << "tipo,nome,dano,cura\n";
    for (const auto& item : itens) {
        arquivo << item->serializar() << "\n";
    }
    return true;
}

bool ArquivoItens::carregarItens(std::vector<std::unique_ptr<Item>>& itens) {
    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) return false;
    std::string linha;
    std::getline(arquivo, linha);
    while (std::getline(arquivo, linha)) {
        try {
            DadosItem dados = parseLinha(linha);
            itens.push_back(ItemFactory::criarItem(dados));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Erro ao ler linha " << linha << ": " << e.what() <<std::endl;
        }
    }
    return true;
}

bool ArquivoItens::arquivoExiste() const {
    return std::filesystem::exists(caminho);
}