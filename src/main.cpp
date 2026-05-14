#include <iostream>
#include <cstdlib>
#include <ctime>

#include "sistema.h"
#include "utils.h"

using namespace std;

int main() {
    Sistema sistema;
    srand(time(nullptr));
    limparTela();
    cout << endl << "===== ARENA DE TORNEIOS =====" << endl;
    cout << "Desenvolvido por: Renato Ikeda Bressan" << endl;
    while (true) {
        sistema.menuPrincipal();
        bool flag = false;
        int option = lerInt("Insira uma das opcoes acima: ");
        switch (option) {
            case 1:
                // Cadastrar jogador
                cout << endl;
                sistema.cadastrarJogador();
                break;
            case 2:
                // Listar jogadores
                cout << endl;
                sistema.listarJogadores();
                break;
            case 3:
                // Buscar jogador
                cout << endl;
                sistema.buscarJogador();
                break;
            case 4:
                // Inserir item em inventário de jogador
                cout << endl;
                sistema.inserirEmInventario();
                break;
            case 5:
                // Listar itens de inventário de jogador
                cout << endl;
                sistema.listarInventario();
                break;
            case 6:
                // Buscar item de inventário de jogador
                cout << endl;
                sistema.buscarDeInventario();
                break;
            case 7:
                // Remover item de inventário de jogador
                cout << endl;
                sistema.removerDeInventario();
                break;
            case 8:
                // Adicionar jogador a fila
                cout << endl;
                sistema.adicionarFila();
                break;
            case 9:
                // Mostrar fila atual
                cout << endl;
                sistema.mostrarFila();
                break;
            case 10:
                // Iniciar partida
                cout << endl;
                sistema.iniciarPartida();
                break;
            case 11:
                // Registrar no histórico
                cout << endl;
                sistema.registrarHistorico();
                break;
            case 12:
                // Desfazer do histórico
                cout << endl;
                sistema.desfazerHistorico();
                break;
            case 13:
                // Mostrar histórico
                cout << endl;
                sistema.mostrarHistorico();
                break;
            case 0:
                // Encerrar o programa
                cout << endl << "Encerrando o programa..." << endl << endl;
                flag = true;
                break;
            default: cout << endl << "Opcao invalida!" << endl << "Retornando ao menu principal..." << endl;
        }
        if (flag) break;
    }
    return 0;
}