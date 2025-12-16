# 🚢 Batalha Naval em C

Este é um projeto desenvolvido como parte do curso [Nome do Curso/Técnico], implementando o clássico jogo de tabuleiro **Batalha Naval** utilizando a linguagem C.

## 📋 Sobre o Projeto

O objetivo foi criar um jogo de estratégia para dois jogadores via terminal, com foco em lógica de matrizes, manipulação de arquivos e estruturação de dados.

### Funcionalidades Principais
- **Multiplayer Local:** Sistema de turnos alternados entre Jogador 1 e Jogador 2.
- **Persistência de Dados:** Possibilidade de salvar o jogo e continuar depois (arquivo `.txt`).
- **Sistema de Visão:** Cada jogador vê seu próprio tabuleiro (com navios) e uma "visão tática" do inimigo (mostrando apenas acertos/erros).
- **Interface Limpa:** Uso de comandos para limpar a tela e manter o segredo das posições.

## 🚀 Como Executar

### Pré-requisitos
Você precisará de um compilador C (como GCC) instalado.

### Compilação e Execução
1. Clone o repositório ou baixe o arquivo `.zip`.
2. Abra o terminal na pasta do projeto.
3. Compile o código:
   ```bash
   gcc BatalhaNaval.c -o batalha_naval

#### Execute o jogo:

No Windows: batalha_naval.exe

No Linux/Mac: ./batalha_naval

🎮 Como Jogar
Posicionamento: Cada jogador deve posicionar 3 navios informando Linha (0-4) e Coluna (0-4).

Batalha: Em cada turno, escolha uma coordenada para atacar o oponente.

X: Acerto (Navio atingido)

O: Erro (Água)

Vitória: Vence quem afundar todos os 3 navios do oponente primeiro.

🛠️ Tecnologias Utilizadas
Linguagem C
