#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <memory>

#include "sistema.h"
#include "sistema_partidas.h"
#include "../utils/utils.h"
#include "../utils/algoritmos.h"
#include "../models/jogador.h"
#include "../models/item.h"
#include "../models/item_arma.h"
#include "../models/item_pocao.h"
#include "../enums/categoria.h"
#include "../enums/tipo.h"

Sistema::Sistema() : arquivoJogadores("src/data/jogadores.csv"), arquivoItens("src/data/itens.csv"), 
                    ultimoIdJogadores(0), ultimoIdItens(0),
                    ordenadoPorId(false), ordenadoPorPontuacao(false), 
                    ordenadoPorNome(false) {}

int Sistema::gerarNovoIdJogadores() {
    return ++ultimoIdJogadores;
}

int Sistema::gerarNovoIdItens() {
    return ++ultimoIdItens;
}

bool Sistema::jogadorExiste(const std::string& nome) {
    return std::any_of(
        jogadores.begin(),
        jogadores.end(),
        [&](const Jogador& jogador) {
            return jogador.getNome() == nome;
        }
    );
}

bool Sistema::itemExiste(const std::string& nome) {
    return std::any_of(
        itensDisponiveis.begin(),
        itensDisponiveis.end(),
        [&](const std::unique_ptr<Item>& item) {
            return item->getNome() == nome;
        }
    );
}

void Sistema::menuPrincipal() {
    std::cout << std::endl;
    std::cout << "| ============== MENU PRINCIPAL ============== |" << std::endl;
    std::cout << "| 1. Cadastrar jogador                         |" << std::endl;
    std::cout << "| 2. Listar jogadores                          |" << std::endl;
    std::cout << "| 3. Buscar jogador                            |" << std::endl;
    std::cout << "| 4. Registrar item                            |" << std::endl;
    std::cout << "| 5. Listar itens disponiveis                  |" << std::endl;
    std::cout << "| 6. Buscar item disponivel                    |" << std::endl;
    std::cout << "| 7. Inserir item em inventario de jogador     |" << std::endl;
    std::cout << "| 8. Listar itens de inventario de jogador     |" << std::endl;
    std::cout << "| 9. Buscar item de inventario de jogador      |" << std::endl;
    std::cout << "| 10. Remover item de inventario de jogador    |" << std::endl;
    std::cout << "| 11. Adicionar jogador a fila                 |" << std::endl;
    std::cout << "| 12. Mostrar fila atual                       |" << std::endl;
    std::cout << "| 13. Iniciar partida                          |" << std::endl;
    std::cout << "| 14. Exibir classificacao                     |" << std::endl;
    std::cout << "| 15. Desfazer do historico                    |" << std::endl;
    std::cout << "| 16. Mostrar historico completo               |" << std::endl;
    std::cout << "| 0. Encerrar o programa                       |" << std::endl;
    std::cout << "| ============================================ |" << std::endl;
    std::cout << std::endl;
}

void Sistema::cadastrarJogador() {
    std::string nome = lerString("Insira o nome do jogador: ");
    capitalizarString(nome);
    if (!jogadores.empty() && jogadorExiste(nome)) {
        std::cout << "Ja existe um jogador com o nome " << nome << "!" << std::endl;
        return;
    }
    std::string nomeCategoria = lerString("Insira a categoria do jogador: ");
    capitalizarString(nomeCategoria);
    int vida = lerInt("Insira a quantidade de vida total do jogador: ");
    while (vida < 50 || vida > 200) {
        std::cout << "Valor de quantidade de vida invalido!" << std::endl;
        vida = lerInt("Insira a quantidade de vida total do jogador: ");
    }
    try {
        Categoria categoria = categoriaFromString(nomeCategoria);
        int id = gerarNovoIdJogadores();
        Jogador jogador = Jogador(id, nome, categoria, vida);
        jogadores.push_back(std::move(jogador));
        ultimoIdJogadores = id;
        ordenadoPorId = false;
        ordenadoPorPontuacao = false;
        std::cout << "Jogador " << nome << " cadastrado com sucesso!" << std::endl;
        jogadores.back().exibirPerfil();
        historico.registrarAcao("Jogador " + nome + " cadastrado.");
    } catch (const std::invalid_argument& e) {
        std::cerr << "Nao foi possivel cadastrar o jogador: " << e.what() << std::endl;
    }
}

void Sistema::listarJogadores() {
    if (jogadores.empty()) {
        std::cout << "Nao ha jogadores para exibir!" << std::endl;
        return;
    }
    if (!ordenadoPorId) {
        ordenarDados(jogadores,
            [](const Jogador& a, const Jogador& b) {
                return a.getId() < b.getId();
            }
        );
        ordenadoPorId = true;
    }
    for (const Jogador& jogador : jogadores) {
        jogador.exibirPerfil();
    }
    std::cout << jogadores.size() << " jogadores exibidos com sucesso!" << std::endl;
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

void Sistema::registrarItem() {
    std::string nome = lerString("Insira o nome do item: ");
    capitalizarString(nome);
    if (!itensDisponiveis.empty() && itemExiste(nome)) {
        std::cout << "Ja existe um item com o nome " << nome << "!" << std::endl;
        return;
    }
    std::string tipoItem = lerString("Insira o tipo do item (arma/pocao): ");
    capitalizarString(tipoItem);
    try {
        Tipo tipo = tipoFromString(tipoItem);
        int id = gerarNovoIdItens();
        if (tipo == Tipo::Arma) {
            int dano = lerInt("Insira o quantificador de dano do item: ");
            while (dano < 100 || dano > 1000 || dano % 10 != 0) {
                std::cout << "Valor de dano invalido!" << std::endl;
                dano = lerInt("Insira o quantificador de dano do item: ");
            }
            std::unique_ptr<Arma> arma = std::make_unique<Arma>(id, nome, dano);
            itensDisponiveis.push_back(std::move(arma));
        }
        if (tipo == Tipo::Pocao) {
            int cura = lerInt("Insira o quantificador de cura do item: ");
            while (cura < 100 || cura > 2000 || cura % 10 != 0) {
                std::cout << "Valor de cura invalida!" << std::endl;
                cura = lerInt("Insira o quantificador de cura do item: ");
            }
            std::unique_ptr<Pocao> pocao = std::make_unique<Pocao>(id, nome, cura);
            itensDisponiveis.push_back(std::move(pocao));
        }
        ordenadoPorNome = false;
        std::cout << "Item " << nome << " registrado com sucesso!" << std::endl;
        itensDisponiveis.back()->exibirItem();
        historico.registrarAcao("Item " + nome + " registrado.");
    } catch (const std::invalid_argument& e) {
        std::cerr << "Nao foi possivel registrar o item: " << e.what() << std::endl;
    }
}

void Sistema::listarItens() {
    if (itensDisponiveis.empty()) {
        std::cout << "Nao ha itens para exibir!" << std::endl;
        return;
    }
    if (!ordenadoPorNome) {
        ordenarDados(itensDisponiveis, 
            [](const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b) {
                return a->getNome() < b->getNome();
            }
        );
        ordenadoPorNome = true;
    }
    for (const auto& item : itensDisponiveis) {
        item->exibirItem();
    }
    std::cout << itensDisponiveis.size() << " itens exibidos com sucesso!" << std::endl;
}

void Sistema::buscarItem() {
    if (itensDisponiveis.empty()) {
        std::cout << "Nao ha itens para buscar!" << std::endl;
        return;
    }
    if (!ordenadoPorNome) {
        ordenarDados(itensDisponiveis, 
            [](const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b) {
                return a->getNome() < b->getNome();
            }
        );
        ordenadoPorNome = true;
    }
    std::string nomeBusca = lerString("Insira o nome do item para busca: ");
    capitalizarString(nomeBusca);
    auto item = buscarItemPorNome(itensDisponiveis, nomeBusca);
    if (item == itensDisponiveis.end()) {
        std::cout << "Item " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    std::cout << "Item encontrado!" << std::endl;
    (*item)->exibirItem();
    std::cout << "Item " << (*item)->getNome() << " exibido com sucesso!" << std::endl;
}

void Sistema::inserirEmInventario() {
    if (jogadores.empty()) {
        std::cout << "Nao ha jogadores para buscar!" << std::endl;
        return;
    }
    if (itensDisponiveis.empty()) {
        std::cout << "Nao ha itens para buscar!" << std::endl;
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
    auto item = buscarItemPorNome(itensDisponiveis, nomeItem);
    if (item == itensDisponiveis.end()) {
        std::cout << "Item " << nomeBusca << " nao encontrado!" << std::endl;
        return;
    }
    jogador->inserirItem(std::move(*item));
    itensDisponiveis.erase(item);
    std::cout << "Item " << nomeItem << " inserido no inventario de " << jogador->getNome() << " com sucesso!" << std::endl;
    historico.registrarAcao("Item " + nomeItem + " inserido no inventario de " + jogador->getNome() + ".");
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
    auto item = jogador->removerItem(nomeItem);
    if (!item) {
        std::cout << "Item " << nomeItem << " nao encontrado!" << std::endl;
        return;
    }
    itensDisponiveis.push_back(std::move(item));
    ordenadoPorNome = false;
    std::cout << "Item " << nomeItem << " removido com sucesso!" << std::endl;
    historico.registrarAcao("Item " + nomeItem + " removido do inventario de " + jogador->getNome() + ".");
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
    ordenadoPorPontuacao = false;
    std::cout << vencedor->getNome() << ": +" << recompensa << "pts." << std::endl;
    std::cout << perdedor->getNome() << ": -" << desconto << "pts." << std::endl;
    historico.registrarAcao(vencedor->getNome() + " venceu partida contra " + perdedor->getNome() + ".");
}

void Sistema::exibirClassificacao() {
    if (jogadores.empty()) {
        std::cout << "Nao ha jogadores para exibir!" << std::endl;
        return;
    }
    std::vector<Jogador*> ranking;
    for (auto& jogador : jogadores) {
        ranking.push_back(&jogador);
    }
    if (!ordenadoPorPontuacao) {
        ordenarDados(ranking,
            [](Jogador* a, Jogador* b) {
                return a->getPontuacao() > b->getPontuacao();
            }
        );
        ordenadoPorPontuacao = true;
    }
    for (const Jogador* jogador : ranking) {
        jogador->exibirPerfil();
    }
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

void Sistema::salvarDados() {
    for (Jogador& jogador : jogadores) {
        auto itens = jogador.extrairItens();
        for (auto& item : itens) {
            itensDisponiveis.push_back(std::move(item));
        }
    }
    ordenarDados(jogadores,
        [](const Jogador& a, const Jogador& b) {
            return a.getId() < b.getId();
        }
    );
    ordenarDados(itensDisponiveis, 
        [](const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b) {
            return a->getNome() < b->getNome();
        }
    );
    bool sucessoJogadores = arquivoJogadores.salvarJogadores(jogadores);
    bool sucessoItens = arquivoItens.salvarItens(itensDisponiveis);
    (sucessoJogadores) ? std::cout << jogadores.size() << " jogadores salvos no arquivo com sucesso!" << std::endl 
                        : std::cout << "Falha ao escrever no arquivo de jogadores!" << std::endl;
    (sucessoItens) ? std::cout << itensDisponiveis.size() << " itens salvos no arquivo com sucesso!" << std::endl 
                    : std::cout << "Falha ao escrever no arquivo de itens!" << std::endl;
    std::cout << std::endl;
}

void Sistema::carregarDados() {
    std::cout << std::endl;
    if (!arquivoJogadores.arquivoExiste()) {
        std::cout << "Arquivo de jogadores nao encontrado/sem registros!" << std::endl;
        return;
    }
    if (!arquivoItens.arquivoExiste()) {
        std::cout << "Arquivo de itens nao encontrado/sem registros!" << std::endl;
        return;
    }
    bool sucessoJogadores = arquivoJogadores.carregarJogadores(jogadores, ultimoIdJogadores);
    bool sucessoItens = arquivoItens.carregarItens(itensDisponiveis, ultimoIdItens);
    (sucessoJogadores) ? std::cout << jogadores.size() << " jogadores carregados do arquivo com sucesso!" << std::endl 
                        : std::cout << "Falha ao ler do arquivo de jogadores!" << std::endl;
    (sucessoItens) ? std::cout << itensDisponiveis.size() << " itens carregados do arquivo com sucesso!" << std::endl 
                    : std::cout << "Falha ao ler do arquivo de itens!" << std::endl;
}