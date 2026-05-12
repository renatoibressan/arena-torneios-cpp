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
                //
                break;
            case 2:
                //
                break;
            case 3:
                //
                break;
            case 4:
                //
                break;
            case 5:
                //
                break;
            case 6:
                //
                break;
            case 7:
                //
                break;
            case 8:
                //
                break;
            case 0:
                cout << "Encerrando o programa..." << endl << endl;
                flag = true;
                break;
            default: cout << "Opcao invalida!" << endl << "Retornando ao menu principal..." << endl;
        }
        if (flag) break;
    }
    return 0;
}