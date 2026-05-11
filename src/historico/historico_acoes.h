#ifndef HISTORICO_ACOES_H
#define HISTORICO_ACOES_H

#include <stack>
#include <string>

class HistoricoAcoes {
    private:
        std::stack<std::string> historico;
    public:
        void registrarAcao(std::string acao);
        void desfazerUltimaAcao();
        void mostrarHistorico();
};

#endif