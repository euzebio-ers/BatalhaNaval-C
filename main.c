#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do jogo
struct Batalha {
    int turno;
    char tabuleiro1[5][5];
    char tabuleiro2[5][5];
    char visao1[5][5];
    char visao2[5][5];
};

// Função para verificar se existe arquivo.
int ExisteJogoSalvo() {
    FILE *arquivo = fopen("jogo_salvo.txt", "r");
    if (arquivo != NULL) {
        fclose(arquivo);
        return 1; // Existe
    }
    return 0; // Não existe
}

// Inicializa retornando uma estrutura inicial do jogo já preenchida
struct Batalha InicializarJogo() {
    struct Batalha jogo;
    jogo.turno = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            jogo.tabuleiro1[i][j] = '~';
            jogo.tabuleiro2[i][j] = '~';
            jogo.visao1[i][j] = '~';
            jogo.visao2[i][j] = '~';
        }
    }
    return jogo;
}

// Salva o estado atual
void SalvarJogo(struct Batalha jogo) {
    FILE *arquivo = fopen("jogo_salvo.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar jogo\n");
        return;
    }

    fprintf(arquivo, "Turno %d\n", jogo.turno);

    // Salva Tabuleiro 1
    fprintf(arquivo, "Tabuleiro 1\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fprintf(arquivo, "%c", jogo.tabuleiro1[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    // Salva Tabuleiro 2
    fprintf(arquivo, "Tabuleiro 2\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fprintf(arquivo, "%c", jogo.tabuleiro2[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    // Salva Visao 1
    fprintf(arquivo, "Visao jogador 1\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fprintf(arquivo, "%c", jogo.visao1[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    // Salva Visao 2
    fprintf(arquivo, "Visao jogador 2\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fprintf(arquivo, "%c", jogo.visao2[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Jogo salvo com sucesso!\n");
}

// Carrega e retorna a estrutura de jogo já preenchida
struct Batalha CarregarJogo() {
    struct Batalha jogo;
    FILE *arquivo = fopen("jogo_salvo.txt", "r");
    char lixo[50];

    fscanf(arquivo, "Turno %d", &jogo.turno);

    // Lê e descarta o texto "Tabuleiro 1"
    fscanf(arquivo, "%s %s", lixo, lixo);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) {
            fscanf(arquivo, " %c", &jogo.tabuleiro1[i][j]);
        }
    }

    // Lê e descarta o texto "Tabuleiro 2"
    fscanf(arquivo, "%s %s", lixo, lixo);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) {
            fscanf(arquivo, " %c", &jogo.tabuleiro2[i][j]);
        }
    }

    // Visao jogador 1
    fscanf(arquivo, "%s %s %s", lixo, lixo, lixo);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) {
            fscanf(arquivo, " %c", &jogo.visao1[i][j]);
        }
    }

    // Visao jogador 2
    fscanf(arquivo, "%s %s %s", lixo, lixo, lixo);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) {
            fscanf(arquivo, " %c", &jogo.visao2[i][j]);
        }
    }

    fclose(arquivo);
    return jogo;
}

void LimparTela() {
    system("cls || clear");
}

void ExibirTabuleiro(char matriz[5][5]) {
    printf("  0 1 2 3 4\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
        for (int j = 0; j < 5; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

void PosicionarNavios(char tabuleiro[5][5], int jogador) {
    int navios = 0;
    int l, c;

    while (navios < 3) {
        LimparTela();
        printf("--- Jogador %d ---\n", jogador);
        printf("Posicione seus navios (Total: 3)\n");
        ExibirTabuleiro(tabuleiro);

        printf("Navio %d - Digite linha e coluna (0 a 4): ", navios + 1);
        scanf("%d %d", &l, &c);

        if (l >= 0 && l < 5 && c >= 0 && c < 5) {
            if (tabuleiro[l][c] == '~') {
                tabuleiro[l][c] = 'N';
                navios++;
            } else {
                printf("Posiçao ocupada! Tente novamente.\n");
                system("pause");
            }
        } else {
            printf("Coordenada invalida! Use 0 a 4.\n");
            system("pause");
        }
    }
    LimparTela();
}

int VerificarVitoria(char tabuleiro[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (tabuleiro[i][j] == 'N') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {

    struct Batalha jogo;
    int opcao;
    int jogoEmAndamento = 1;

    printf("Deseja carregar um jogo salvo? (1-Sim, 0-Nao): ");
    scanf("%d", &opcao);

    if (opcao == 1 && ExisteJogoSalvo()) {
        jogo = CarregarJogo();
        printf("Jogo carregado com sucesso!\n");
        system("pause");
    } else {
        if(opcao == 1) printf("Arquivo nao encontrado. Iniciando novo jogo.\n");
        jogo = InicializarJogo();
        PosicionarNavios(jogo.tabuleiro1, 1);
        PosicionarNavios(jogo.tabuleiro2, 2);
    }

    while (jogoEmAndamento) {
        LimparTela();

        int jogadorAtual = jogo.turno;

        printf("=== TURNO DO JOGADOR %d ===\n", jogadorAtual);

        if (jogadorAtual == 1) {
            ExibirTabuleiro(jogo.visao1);
        } else {
            ExibirTabuleiro(jogo.visao2);
        }

        printf("\n1. Atacar\n2. Salvar e Sair\nEscolha: ");
        int acao;
        scanf("%d", &acao);

        if (acao == 2) {
            SalvarJogo(jogo);
            break;
        }

        int l, c;
        printf("Digite as coordenadas do ataque (linha coluna): ");
        scanf("%d %d", &l, &c);

        if (l >= 0 && l < 5 && c >= 0 && c < 5) {
            if (jogadorAtual == 1) {
                // Jogador 1 ataca Tabuleiro 2
                if (jogo.tabuleiro2[l][c] == 'N') {
                    printf("ACERTOU, MISERAVI!\n");
                    jogo.tabuleiro2[l][c] = 'X';
                    jogo.visao1[l][c] = 'X';
                } else if (jogo.tabuleiro2[l][c] == 'X' || jogo.tabuleiro2[l][c] == 'O') {
                    printf("Você ja atacou aqui!\n");
                } else {
                    printf("ERROU (CAIU NA AGUA MISERAVI)!\n");
                    jogo.visao1[l][c] = 'O';
                }

                if (VerificarVitoria(jogo.tabuleiro2)) {
                    printf("PARABENS! JOGADOR 1 VENCEU!\n");
                    jogoEmAndamento = 0;
                } else {
                    jogo.turno = 2; // Passa a vez
                }

            } else {
                // Jogador 2 ataca Tabuleiro 1
                if (jogo.tabuleiro1[l][c] == 'N') {
                    printf("ACERTOU, MISERAVI!\n");
                    jogo.tabuleiro1[l][c] = 'X';
                    jogo.visao2[l][c] = 'X';
                } else if (jogo.tabuleiro1[l][c] == 'X' || jogo.tabuleiro1[l][c] == 'O') {
                    printf("Voce ja atacou aqui!\n");
                } else {
                    printf("ERROU (CAIU NA AGUA MISERAVI)!\n");
                    jogo.visao2[l][c] = 'O';
                }

                if (VerificarVitoria(jogo.tabuleiro1)) {
                    printf("PARABENS! JOGADOR 2 VENCEU!\n");
                    jogoEmAndamento = 0;
                } else {
                    jogo.turno = 1; // Passa a vez
                }
            }
            system("pause");

        } else {
            printf("Coordenada invalida!\n");
            system("pause");
        }
    }
    return 0;
}