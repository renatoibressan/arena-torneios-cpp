#ifndef ARQUIVO_ITENS_H
#define ARQUIVO_ITENS_H

#include <vector>
#include <string>
#include <memory>

#include "../models/item.h"

class ArquivoItens {
    private:
        std::string caminho;
    public:
        ArquivoItens(const std::string& caminho);
        bool salvarItens(const std::vector<std::unique_ptr<Item>>& itens) const;
        bool carregarItens(std::vector<std::unique_ptr<Item>>& itens);
        bool arquivoExiste() const;
};

#endif