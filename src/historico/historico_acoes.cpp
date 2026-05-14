#include <iostream>
#include <stack>
#include <string>

#include "historico_acoes.h"

void HistoricoAcoes::registrarAcao(std::string acao) {
    historico.push(acao);
}

std::string HistoricoAcoes::desfazerUltimaAcao() {
    if (historicoVazio()) return "";
    std::string acao = historico.top();
    historico.pop();
    return acao;
}

void HistoricoAcoes::mostrarHistorico(const std::string& mensagem) {
    std::cout << mensagem << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::stack<std::string> temp = historico;
    while (!temp.empty()) {
        std::cout << temp.top() << std::endl;
        temp.pop();
    }
    std::cout << "---------------------------------------------" << std::endl;
}

bool HistoricoAcoes::historicoVazio() const {
    return historico.empty();
}