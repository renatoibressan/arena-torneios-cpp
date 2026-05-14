#include <iostream>
#include <string>

#include "sistema.h"
#include "../utils/utils.h"
#include "../categoria/categoria.h"
#include "../algoritmos/algoritmos.h"
#include "../partidas/sistema_partidas.h"

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
    std::cout << "11. Desfazer do historico" << std::endl;
    std::cout << "12. Mostrar historico completo" << std::endl;
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
        jogadores.emplace_back(id, nome, categoria, vida);
        ultimoId = id;
        ordenado = false;
        std::cout << "Jogador cadastrado com sucesso!" << std::endl;
        jogadores.back().exibirPerfil();
        historico.registrarAcao("Jogador " + nome + " cadastrado.");
    } catch (const char *e) {
        std::cerr << "Nao foi possivel cadastrar o jogador: " << e << std::endl;
    }
}

void Sistema::listarJogadores() {
    if (jogadores.empty()) {
        std::cout << "Nao ha jogadores para exibir!" << std::endl;
        return;
    }
    if (!ordenado) {
        ordenarRanking(jogadores);
        ordenado = true;
    }
    for (Jogador jogador : jogadores) {
        jogador.exibirPerfil();
    }
}

void Sistema::buscarJogador() {
    if (jogadores.empty()) {
        std::cout << "Nao ha jogadores para buscar!" << std::endl;
        return;
    }
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
    if (jogadores.empty()) {
        std::cout << "Nao ha jogadores para buscar!" << std::endl;
        return;
    }
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
    while (poderDano <= 0 || poderDano > 1000 || poderDano % 10 != 0) {
        std::cout << "Valor de poder de dano invalido!" << std::endl;
        poderDano = lerInt("Insira o poder de dano do item: ");
    }
    try {
        Tipo tipoItem = tipoFromString(nomeTipoItem);
        Item item = Item(nomeItem, tipoItem, grauRaridade, poderDano);
        jogador->inserirItem(item);
        std::cout << "Item inserido no inventario de " << jogador->getNome() << " com sucesso!" << std::endl;
        item.exibirItem();
        historico.registrarAcao("Item " + nomeItem + " inserido no inventario de " + jogador->getNome() + ".");
    } catch (const char *e) {
        std::cerr << "Nao foi possivel inserir o item no inventario do jogador " << jogador->getNome() << ": " << e << std::endl;
    }
}

void Sistema::listarInventario() {
    if (jogadores.empty()) {
        std::cout << "Nao ha jogadores para buscar!" << std::endl;
        return;
    }
    std::string nomeBusca = lerString("Insira o nome do jogador para busca: ");
    capitalizarString(nomeBusca);
    Jogador *jogador = buscarJogadorPorNome(jogadores, nomeBusca);
    if (!jogador) {
        std::cout << "Jogador " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    if (jogador->inventarioVazio()) {
        std::cout << jogador->getNome() << " nao tem itens para listar!" << std::endl;
        return;
    }
    jogador->listarItens();
}

void Sistema::buscarDeInventario() {
    if (jogadores.empty()) {
        std::cout << "Nao ha jogadores para buscar!" << std::endl;
        return;
    }
    std::string nomeBusca = lerString("Insira o nome do jogador para busca: ");
    capitalizarString(nomeBusca);
    Jogador *jogador = buscarJogadorPorNome(jogadores, nomeBusca);
    if (!jogador) {
        std::cout << "Jogador " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    if (jogador->inventarioVazio()) {
        std::cout << jogador->getNome() << " nao tem itens para buscar!" << std::endl;
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
    if (jogadores.empty()) {
        std::cout << "Nao ha jogadores para buscar!" << std::endl;
        return;
    }
    std::string nomeBusca = lerString("Insira o nome do jogador para busca: ");
    capitalizarString(nomeBusca);
    Jogador *jogador = buscarJogadorPorNome(jogadores, nomeBusca);
    if (!jogador) {
        std::cout << "Jogador " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    if (jogador->inventarioVazio()) {
        std::cout << jogador->getNome() << " nao tem itens para remover!" << std::endl;
        return;
    }
    std::string nomeItem = lerString("Insira o nome do item para remocao: ");
    capitalizarString(nomeItem);
    bool removido = jogador->removerItem(nomeItem);
    (!removido) ? std::cout << "Item " << nomeItem << " nao encontrado!" << std::endl : std::cout << "Item " << nomeItem << " removido com sucesso!" << std::endl;
    if (removido) historico.registrarAcao("Item " + nomeItem + " removido do inventario de " + jogador->getNome() + ".");
}

void Sistema::adicionarFila() {
    if (jogadores.empty()) {
        std::cout << "Nao ha jogadores para buscar!" << std::endl;
        return;
    }
    std::string nomeBusca = lerString("Insira o nome do jogador para busca: ");
    capitalizarString(nomeBusca);
    Jogador *jogador = buscarJogadorPorNome(jogadores, nomeBusca);
    if (!jogador) {
        std::cout << "Jogador " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    if (jogador->inventarioVazio()) {
        std::cout << jogador->getNome() << " nao tem itens para realizar partidas!" << std::endl;
        return;
    }
    int id = jogador->getId();
    fila.enfileirar(id);
    std::cout << "Jogador " << jogador->getNome() << " adicionado a fila com sucesso!" << std::endl;
    historico.registrarAcao(jogador->getNome() + " adicionado a fila de espera para partidas.");
}

void Sistema::mostrarFila() {
    if (fila.filaVazia()) {
        std::cout << "Fila de jogadores vazia!" << std::endl;
        return;
    }
    fila.mostrarFila("Fila atual:");
}

void Sistema::iniciarPartida() {
    if (fila.filaVazia() || fila.tamanhoFila() < 2) {
        std::cout << "Fila de jogadores vazia/insuficiente!" << std::endl;
        return;
    }
    int id1 = fila.desenfileirar();
    Jogador *j1 = buscarJogadorPorId(jogadores, id1);
    if (j1->inventarioVazio()) {
        std::cout << j1->getNome() << " nao tem itens para realizar a partida!" << std::endl;
        return;
    }
    int id2 = fila.desenfileirar();
    Jogador *j2 = buscarJogadorPorId(jogadores, id2);
    if (j2->inventarioVazio()) {
        std::cout << j2->getNome() << " nao tem itens para realizar a partida!" << std::endl;
        return;
    }
    ResultadoPartida resultado = executarPartida(j1, j2);
    const int recompensa = resultado.turnos * 10;
    const int desconto = recompensa / 2;
    Jogador *vencedor = buscarJogadorPorId(jogadores, resultado.idVencedor);
    Jogador *perdedor = buscarJogadorPorId(jogadores, resultado.idPerdedor);
    if (!vencedor || !perdedor) {
        std::cout << "Jogadores nao encontrados!" << std::endl;
        return;
    }
    vencedor->adicionarPontuacao(recompensa);
    perdedor->removerPontuacao(desconto);
    std::cout << vencedor->getNome() << ": +" << recompensa << "pts." << std::endl;
    std::cout << perdedor->getNome() << ": -" << desconto << "pts." << std::endl;
    historico.registrarAcao(vencedor->getNome() + " venceu partida contra " + perdedor->getNome() + ".");
}

void Sistema::desfazerHistorico() {
    if (historico.historicoVazio()) {
        std::cout << "Historico de acoes vazia!" << std::endl;
        return;
    }
    std::string acao = historico.desfazerUltimaAcao();
    if (!acao.empty()) std::cout << "Acao desfeita com sucesso! (" << acao << ")" << std::endl;
}

void Sistema::mostrarHistorico() {
    if (historico.historicoVazio()) {
        std::cout << "Historico de acoes vazia!" << std::endl;
        return;
    }
    historico.mostrarHistorico("Historico completo:");
}