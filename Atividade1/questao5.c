#include <stdio.h>

// Função Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para verificar a presença de um número usando busca sequencial
int buscaSequencial(int arr[], int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i; // Retorna a posição se encontrado
        }
    }
    return -1; // Retorna -1 se não encontrado
}

// Função para verificar a presença de um número usando busca binária
int buscaBinaria(int arr[], int inicio, int fim, int num) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == num) {
            return meio; // Retorna a posição se encontrado
        }

        if (arr[meio] < num) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // Retorna -1 se não encontrado
}

int main() {
    int numeros[15];

    // Cadastro de números não permitindo repetições
    printf("Digite 15 numeros diferentes:\n");
    for (int i = 0; i < 15; ++i) {
        int repetido;
        do {
            repetido = 0; // Inicializa repetido como falso
            printf("Digite o numero %d: ", i + 1);
            scanf("%d", &numeros[i]);

            // Verifica se o número já foi cadastrado
            for (int j = 0; j < i; ++j) {
                if (numeros[j] == numeros[i]) {
                    repetido = 1; // Configura repetido como verdadeiro
                    printf("Numero repetido. Digite novamente.\n");
                    break;
                }
            }
        } while (repetido);
    }

    // Ordenar o vetor
    bubbleSort(numeros, 15);

    // Imprimir o vetor ordenado
    printf("\nNumeros ordenados:\n");
    for (int i = 0; i < 15; ++i) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // Verificar a presença de um número e sua posição usando busca sequencial
    int numProcurado;
    printf("\nDigite um numero para verificar sua presenca e posicao (usando busca sequencial): ");
    scanf("%d", &numProcurado);

    int posicaoSequencial = buscaSequencial(numeros, 15, numProcurado);
    if (posicaoSequencial != -1) {
        printf("O numero %d foi encontrado na posicao %d (usando busca sequencial).\n", numProcurado, posicaoSequencial);
        if (posicaoSequencial % 2 == 0) {
            printf("Esta na posicao par do vetor.\n");
        } else {
            printf("Esta na posicao impar do vetor.\n");
        }
    } else {
        printf("O numero %d nao foi encontrado no vetor.\n", numProcurado);
    }

    // Verificar a presença de um número e sua posição usando busca binária
    printf("\nDigite um numero para verificar sua presenca e posicao (usando busca binaria): ");
    scanf("%d", &numProcurado);

    int posicaoBinaria = buscaBinaria(numeros, 0, 14, numProcurado);
    if (posicaoBinaria != -1) {
        printf("O numero %d foi encontrado na posicao %d (usando busca binaria).\n", numProcurado, posicaoBinaria);
        if (posicaoBinaria % 2 == 0) {
            printf("Esta na posicao par do vetor.\n");
        } else {
            printf("Esta na posicao impar do vetor.\n");
        }
    } else {
        printf("O numero %d nao foi encontrado no vetor.\n", numProcurado);
    }

    return 0;
}
