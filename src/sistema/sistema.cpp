#include <iostream>
#include <string>

#include "sistema.h"
#include "../utils/utils.h"
#include "../categoria/categoria.h"
#include "../algoritmos/algoritmos.h"

Sistema::Sistema() : ultimoId(0), ordenado(false) {}

int Sistema::gerarNovoId() {
    return ++ultimoId;
}

void Sistema::menuPrincipal() {
    std::cout << std::endl << "====== MENU PRINCIPAL ======" << std::endl;
    std::cout << "1. Cadastrar jogador" << std::endl;
    std::cout << "2. Listar jogadores" << std::endl;
    std::cout << "3. Buscar jogador" << std::endl;
    std::cout << "4. Inserir item em inventario de jogador" << std::endl;
    std::cout << "5. Listar itens de inventario de jogador" << std::endl;
    std::cout << "6. Buscar item de inventario de jogador" << std::endl;
    std::cout << "7. Remover item de inventario de jogador" << std::endl;
    std::cout << "8. Adicionar jogador a fila" << std::endl;
    std::cout << "9. Mostrar fila atual" << std::endl;
    std::cout << "10. Iniciar partida" << std::endl;
    std::cout << "11. Registrar no historico" << std::endl;
    std::cout << "12. Desfazer do historico" << std::endl;
    std::cout << "13. Mostrar historico" << std::endl;
    std::cout << "0. Encerrar o programa" << std::endl << std::endl;
}

void Sistema::cadastrarJogador() {
    int id = gerarNovoId();
    std::string nome = lerString("Insira o nome do jogador: ");
    capitalizarString(nome);
    std::string nomeCategoria = lerString("Insira a categoria do jogador: ");
    capitalizarString(nomeCategoria);
    int vida = lerInt("Insira a quantidade de vida total do jogador: ");
    while (vida < 0 || vida > 200) {
        std::cout << "Valor de quantidade de vida invalido!" << std::endl;
        vida = lerInt("Insira a quantidade de vida total do jogador: ");
    }
    try {
        Categoria categoria = categoriaFromString(nomeCategoria);
        ultimoId = id;
        ordenado = false;
        jogadores.emplace_back(id, nome, categoria, vida);
        std::cout << "Jogador cadastrado com sucesso!" << std::endl;
        jogadores.back().exibirPerfil();
    } catch (const char *e) {
        std::cerr << "Nao foi possivel cadastrar o jogador: " << e << std::endl;
    }
}

void Sistema::listarJogadores() {
    if (!ordenado) {
        ordenarRanking(jogadores);
        ordenado = true;
    }
    for (Jogador jogador : jogadores) {
        jogador.exibirPerfil();
    }
}

void Sistema::buscarJogador() {
    std::string nomeBusca = lerString("Insira o nome do jogador para busca: ");
    capitalizarString(nomeBusca);
    Jogador *jogador = buscarJogadorPorNome(jogadores, nomeBusca);
    if (!jogador) {
        std::cout << "Jogador " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    std::cout << "Jogador encontrado!" << std::endl;
    jogador->exibirPerfil();
    std::cout << "Jogador " << jogador->getNome() << " exibido com sucesso!" << std::endl;
}

void Sistema::inserirEmInventario() {
    std::string nomeBusca = lerString("Insira o nome do jogador para busca: ");
    capitalizarString(nomeBusca);
    Jogador *jogador = buscarJogadorPorNome(jogadores, nomeBusca);
    if (!jogador) {
        std::cout << "Jogador " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    std::string nomeItem = lerString("Insira o nome do item: ");
    capitalizarString(nomeItem);
    std::string nomeTipoItem = lerString("Insira o tipo do item: ");
    capitalizarString(nomeTipoItem);
    int grauRaridade = lerInt("Insira o grau de raridade do item: ");
    while (grauRaridade < 1 || grauRaridade > 5) {
        std::cout << "Valor de grau de raridade invalido!" << std::endl;
        grauRaridade = lerInt("Insira o grau de raridade do item: ");
    }
    int poderDano = lerInt("Insira o poder de dano do item: ");
    while (poderDano < 0 || poderDano > 1000 || poderDano % 10 != 0) {
        std::cout << "Valor de poder de dano invalido!" << std::endl;
        poderDano = lerInt("Insira o poder de dano do item: ");
    }
    try {
        Tipo tipoItem = tipoFromString(nomeTipoItem);
        Item item = Item(nomeItem, tipoItem, grauRaridade, poderDano);
        jogador->inserirItem(item);
        std::cout << "Item inserido no inventario de " << jogador->getNome() << " com sucesso!" << std::endl;
        item.exibirItem();
    } catch (const char *e) {
        std::cerr << "Nao foi possivel inserir o item no inventario do jogador " << jogador->getNome() << ": " << e << std::endl;
    }
}

void Sistema::listarInventario() {
    std::string nomeBusca = lerString("Insira o nome do jogador para busca: ");
    capitalizarString(nomeBusca);
    Jogador *jogador = buscarJogadorPorNome(jogadores, nomeBusca);
    if (!jogador) {
        std::cout << "Jogador " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    jogador->listarItens();
}

void Sistema::buscarDeInventario() {
    std::string nomeBusca = lerString("Insira o nome do jogador para busca: ");
    capitalizarString(nomeBusca);
    Jogador *jogador = buscarJogadorPorNome(jogadores, nomeBusca);
    if (!jogador) {
        std::cout << "Jogador " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    std::string nomeItem = lerString("Insira o nome do item para busca: ");
    capitalizarString(nomeItem);
    Item *item = jogador->buscarItem(nomeItem);
    if (!item) {
        std::cout << "Item " << nomeItem << " nao encontrado!" << std::endl;
        return;
    }
    std::cout << "Item encontrado!" << std::endl;
    item->exibirItem();
    std::cout << "Item " << item->getNome() << " exibido com sucesso!" << std::endl;
}

void Sistema::removerDeInventario() {
    std::string nomeBusca = lerString("Insira o nome do jogador para busca: ");
    capitalizarString(nomeBusca);
    Jogador *jogador = buscarJogadorPorNome(jogadores, nomeBusca);
    if (!jogador) {
        std::cout << "Jogador " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    std::string nomeItem = lerString("Insira o nome do item para remocao: ");
    capitalizarString(nomeItem);
    bool removido = jogador->removerItem(nomeItem);
    (!removido) ? std::cout << "Item " << nomeItem << " nao encontrado!" << std::endl : std::cout << "Item " << nomeItem << " removido com sucesso!" << std::endl;
}

void Sistema::adicionarFila() {
}

void Sistema::mostrarFila() {
}

void Sistema::iniciarPartida() {
}

void Sistema::registrarHistorico() {
}

void Sistema::desfazerHistorico() {
}

void Sistema::mostrarHistorico() {
}