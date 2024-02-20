#include <stdio.h>

// Estrutura para armazenar os dados do produto
struct Produto {
    int codigo;
    char descricao[50];
    float preco;
};

// Função Bubble Sort
void bubbleSort(struct Produto arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].codigo > arr[j + 1].codigo) {
                // Troca
                struct Produto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Busca sequencial
int buscaSequencial(struct Produto arr[], int n, int chave) {
    int comparacoes = 0;
    for (int i = 0; i < n; i++) {
        comparacoes++;
        if (arr[i].codigo == chave) {
            return comparacoes; // Produto encontrado
        }
    }
    return comparacoes; // Produto não encontrado
}

// Busca binária
int buscaBinaria(struct Produto arr[], int inicio, int fim, int chave) {
    int comparacoes = 0;
    while (inicio <= fim) {
        comparacoes++;
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio].codigo == chave) {
            return comparacoes; // Produto encontrado
        }

        if (arr[meio].codigo < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return comparacoes; // Produto não encontrado
}

int main() {
    struct Produto produtos[12];

    // Cadastro de dados dos produtos
    for (int i = 0; i < 12; ++i) {
        printf("Digite o codigo do produto %d: ", i + 1);
        scanf("%d", &produtos[i].codigo);
        while (getchar() != '\n');


        printf("Digite a descricao do produto %d: ", i + 1);
        fgets(produtos[i].descricao, sizeof(produtos[i].descricao), stdin);

        printf("Digite o preco do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);
        while (getchar() != '\n');
    }

    // Ordenação usando Bubble Sort
    bubbleSort(produtos, 12);

    // Menu de opções de busca
    int opcao;
    do {
        printf("\nOpcoes de busca:\n");
        printf("1. Busca sequencial\n");
        printf("2. Busca binaria\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                // Busca sequencial
                int chaveSequencial;
                printf("Digite o codigo para buscar (busca sequencial): ");
                scanf("%d", &chaveSequencial);
                int comparacoesSequencial = buscaSequencial(produtos, 12, chaveSequencial);
                printf("Numero de comparacoes na busca sequencial: %d\n", comparacoesSequencial);
                break;
            }
            case 2: {
                // Busca binária
                int chaveBinaria;
                printf("Digite o codigo para buscar (busca binaria): ");
                scanf("%d", &chaveBinaria);
                int comparacoesBinaria = buscaBinaria(produtos, 0, 11, chaveBinaria);
                printf("Numero de comparacoes na busca binaria: %d\n", comparacoesBinaria);
                break;
            }
            case 0:
                // Sair do programa
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
