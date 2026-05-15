# Arena Torneios C++

## Descrição

Arena Torneios C++ é um sistema gerenciador de torneios de partidas entre jogadores desenvolvido em C++. O projeto permite cadastrar jogadores, organizar partidas e manter o histórico das ações realizadas no torneio.

## Funcionalidades Principais

- Cadastro e gerenciamento de jogadores
- Criação e organização de partidas
- Controle de inventário e itens dos jogadores
- Histórico de ações do sistema
- Estrutura modular com serviços, repositório e modelos

## Pré-requisitos

- Compilador C++ compatível com C++11 ou superior
- Make (opcional, se houver script de compilação)

## Como instalar e rodar

1. Clone o repositório:

   ```bash
   git clone https://seu-repositorio.git
   cd arena-torneios-cpp
   ```

2. Compile o projeto:

   ```bash
   g++ -std=c++11 -o bin/main src/main/main.cpp src/models/*.cpp src/repository/*.cpp src/service/*.cpp src/utils/*.cpp
   ```

   > Se o projeto tiver um `Makefile`, use `make` em vez do comando acima.

3. Execute o binário gerado:

   ```bash
   ./bin/main
   ```

## Exemplo de Uso

Após executar o programa, siga as opções exibidas no menu para:

1. Cadastrar jogadores
2. Criar partidas entre jogadores cadastrados
3. Visualizar o histórico de ações
4. Gerenciar inventário e itens dos jogadores

O fluxo exato dependerá das opções oferecidas pela interface do sistema em `src/main/main.cpp`.

## Tecnologias Utilizadas

- C++ (padrão C++11 ou superior)
- Estrutura modular com arquivos de código fonte organizados em `models`, `repository`, `service` e `utils`

## Como contribuir

1. Faça um fork deste repositório.
2. Crie uma branch com sua funcionalidade ou correção:

   ```bash
   git checkout -b minha-melhoria
   ```

3. Faça suas alterações.
4. Faça commit das mudanças:

   ```bash
   git commit -m "Descrição da melhoria"
   ```

5. Envie para o seu repositório e abra um pull request.

## Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.
