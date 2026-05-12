#include <iostream>
#include <cstdlib>
#include <ctime>

#include "sistema.h"
#include "utils.h"

using namespace std;

int main() {
    Sistema sistema;
    srand(time(0));
    limparTela();
    cout << endl << "===== ARENA DE TORNEIOS =====" << endl;
    cout << "Desenvolvido por: Renato Bressan" << endl;
    while (true) {
        sistema.menuPrincipal();
        bool flag = false;
        int option = lerInt("Insira uma das opcoes acima: ");
        switch (option) {
            case 1:
                // Cadastrar jogador
                sistema.cadastrarJogador();
                break;
            case 2:
                // Listar jogadores
                sistema.listarJogadores();
                break;
            case 3:
                // Buscar jogador
                sistema.buscarJogador();
                break;
            case 4:
                // Inserir item em inventário de jogador
                sistema.inserirEmInventario();
                break;
            case 5:
                // Listar itens de inventário de jogador
                sistema.listarInventario();
                break;
            case 6:
                // Buscar item de inventário de jogador
                sistema.buscarDeInventario();
                break;
            case 7:
                // Remover item de inventário de jogador
                sistema.removerDeInventario();
                break;
            case 8:
                // Adicionar jogador a fila
                sistema.adicionarFila();
                break;
            case 9:
                // Mostrar fila atual
                sistema.mostrarFila();
                break;
            case 10:
                // Iniciar partida
                sistema.iniciarPartida();
                break;
            case 11:
                // Registrar no histórico
                sistema.registrarHistorico();
                break;
            case 12:
                // Desfazer do histórico
                sistema.desfazerHistorico();
                break;
            case 13:
                // Mostrar histórico
                sistema.mostrarHistorico();
                break;
            case 0:
                // Encerrar o programa
                cout << "Encerrando o programa..." << endl << endl;
                flag = true;
                break;
            default: cout << "Opcao invalida!" << endl << "Retornando ao menu principal..." << endl;
        }
        if (flag) break;
    }
    return 0;
}