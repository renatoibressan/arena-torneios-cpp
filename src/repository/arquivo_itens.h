#ifndef ARQUIVO_ITENS_H
#define ARQUIVO_ITENS_H

#include <vector>
#include <string>

#include "../models/item.h"

class ArquivoItens {
    private:
        std::string caminho;
    public:
        ArquivoItens(const std::string& caminho);
        bool salvarItens(const std::vector<Item>& itens) const;
        bool carregarItens(std::vector<Item>& itens) const;
        bool arquivoExiste() const;
};

#endif