#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída para funções como printf

// Definição de constantes para o tamanho do tabuleiro e dos navios, e para os valores das células
#define TAMANHO_TABULEIRO 10 // O tabuleiro terá 10x10 células
#define TAMANHO_NAVIO 3      // Cada navio terá 3 posições de comprimento
#define AGUA 0               // Valor que representa uma célula de água no tabuleiro
#define NAVIO 3              // Valor que representa uma parte de um navio no tabuleiro

/**
 * @brief Função para exibir o tabuleiro de Batalha Naval no console.
 *
 * @param tabuleiro A matriz bidimensional que representa o tabuleiro.
 */
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Imprime os números das colunas para referência
    printf("  "); // Espaço para alinhar com as linhas
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%d ", col); // Imprime o índice da coluna
    }
    printf("\n"); // Nova linha após os cabeçalhos das colunas

    // Imprime uma linha separadora para melhorar a visualização
    printf("--");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("--");
    }
    printf("\n");

    // Percorre cada linha do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d|", i); // Imprime o número da linha seguido de um separador

        // Percorre cada coluna da linha atual
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da célula (0 para água, 3 para navio)
        }
        printf("\n"); // Nova linha após imprimir todos os elementos da linha atual
    }
}

/**
 * @brief Função para posicionar um navio no tabuleiro.
 * Realiza validações para garantir que o navio esteja dentro dos limites do tabuleiro
 * e que não se sobreponha a outro navio já existente.
 *
 * @param tabuleiro A matriz bidimensional do tabuleiro.
 * @param linhaInicial A linha inicial onde o navio será posicionado.
 * @param colunaInicial A coluna inicial onde o navio será posicionado.
 * @param orientacao A orientação do navio ('H' para horizontal, 'V' para vertical).
 * @return 1 se o navio foi posicionado com sucesso, 0 caso contrário.
 */
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial, char orientacao) {
    // Validação de limites e sobreposição para navio horizontal
    if (orientacao == 'H' || orientacao == 'h') { // Se a orientação for Horizontal
        // Verifica se o navio ultrapassa os limites do tabuleiro horizontalmente ou verticalmente
        if (colunaInicial < 0 || colunaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO || linhaInicial < 0 || linhaInicial >= TAMANHO_TABULEIRO) {
            printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
            return 0; // Retorna 0 indicando falha
        }
        // Verifica se há sobreposição com outro navio
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (tabuleiro[linhaInicial][colunaInicial + j] == NAVIO) {
                printf("Erro: Navio horizontal se sobrepõe a outro navio.\n");
                return 0; // Retorna 0 indicando falha
            }
        }
        // Posiciona o navio preenchendo as células com o valor NAVIO
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[linhaInicial][colunaInicial + j] = NAVIO;
        }
    }
    // Validação de limites e sobreposição para navio vertical
    else if (orientacao == 'V' || orientacao == 'v') { // Se a orientação for Vertical
        // Verifica se o navio ultrapassa os limites do tabuleiro verticalmente ou horizontalmente
        if (linhaInicial < 0 || linhaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO || colunaInicial < 0 || colunaInicial >= TAMANHO_TABULEIRO) {
            printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
            return 0; // Retorna 0 indicando falha
        }
        // Verifica se há sobreposição com outro navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaInicial + i][colunaInicial] == NAVIO) {
                printf("Erro: Navio vertical se sobrepõe a outro navio.\n");
                return 0; // Retorna 0 indicando falha
            }
        }
        // Posiciona o navio preenchendo as células com o valor NAVIO
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaInicial + i][colunaInicial] = NAVIO;
        }
    }
    // Caso a orientação seja inválida
    else {
        printf("Erro: Orientação de navio inválida. Use 'H' para horizontal ou 'V' para vertical.\n");
        return 0; // Retorna 0 indicando falha
    }
    return 1; // Retorna 1 indicando sucesso no posicionamento
}

/**
 * @brief Função principal do programa.
 * Inicializa o tabuleiro, define as coordenadas dos navios,
 * tenta posicioná-los e exibe o tabuleiro final.
 */
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Declara a matriz do tabuleiro

    // Inicializa todas as posições do tabuleiro com AGUA (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Define as coordenadas iniciais para o primeiro navio (horizontal)
    int linhaNavioH = 2;
    int colunaNavioH = 3;

    // Define as coordenadas iniciais para o segundo navio (vertical)
    int linhaNavioV = 5;
    int colunaNavioV = 6;

    printf("--- Posicionamento dos Navios ---\n");

    // Tenta posicionar o primeiro navio (horizontal)
    if (posicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, 'H')) {
        printf("Navio Horizontal posicionado com sucesso!\n");
        // Exibe as coordenadas de cada parte do navio horizontal
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            printf("  Parte %d: (%d, %d)\n", j + 1, linhaNavioH, colunaNavioH + j);
        }
    } else {
        printf("Não foi possível posicionar o primeiro navio. Verifique as coordenadas.\n");
        return 1; // Sai do programa se o posicionamento falhar
    }

    printf("\n"); // Adiciona uma linha em branco para melhor legibilidade

    // Tenta posicionar o segundo navio (vertical)
    if (posicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, 'V')) {
        printf("Navio Vertical posicionado com sucesso!\n");
        // Exibe as coordenadas de cada parte do navio vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            printf("  Parte %d: (%d, %d)\n", i + 1, linhaNavioV + i, colunaNavioV);
        }
    } else {
        printf("Não foi possível posicionar o segundo navio. Verifique as coordenadas.\n");
        return 1; // Sai do programa se o posicionamento falhar
    }

    printf("\n--- Tabuleiro Final ---\n");
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}