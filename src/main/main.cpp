#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../service/sistema.h"
#include "../utils/utils.h"

using namespace std;

int main() {
    Sistema sistema;
    srand(time(nullptr));
    limparTela();
    cout << endl << "================ ARENA DE TORNEIOS ================" << endl;
    cout << "Desenvolvido por: Renato Ikeda Bressan" << endl;
    sistema.carregarDados();
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
                // Registrar item
                cout << endl;
                sistema.registrarItem();
                break;
            case 5:
                // Listar itens
                cout << endl;
                sistema.listarItens();
                break;
            case 6:
                // Buscar item
                cout << endl;
                sistema.buscarItem();
                break;
            case 7:
                // Inserir item em inventário de jogador
                cout << endl;
                sistema.inserirEmInventario();
                break;
            case 8:
                // Listar itens de inventário de jogador
                cout << endl;
                sistema.listarInventario();
                break;
            case 9:
                // Buscar item de inventário de jogador
                cout << endl;
                sistema.buscarDeInventario();
                break;
            case 10:
                // Remover item de inventário de jogador
                cout << endl;
                sistema.removerDeInventario();
                break;
            case 11:
                // Adicionar jogador à fila
                cout << endl;
                sistema.adicionarFila();
                break;
            case 12:
                // Mostrar fila atual
                cout << endl;
                sistema.mostrarFila();
                break;
            case 13:
                // Iniciar partida
                cout << endl;
                sistema.iniciarPartida();
                break;
            case 14:
                // Exibir classificação
                cout << endl;
                sistema.exibirClassificacao();
                break;
            case 15:
                // Desfazer do histórico
                cout << endl;
                sistema.desfazerHistorico();
                break;
            case 16:
                // Mostrar histórico completo
                cout << endl;
                sistema.mostrarHistorico();
                break;
            case 0:
                // Encerrar o programa
                cout << endl << "Encerrando o programa..." << endl;
                flag = true;
                break;
            default: cout << endl << "Opcao invalida!" << endl << "Retornando ao menu principal..." << endl;
        }
        if (flag) break;
    }
    sistema.salvarDados();
    return 0;
}