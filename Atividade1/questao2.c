#include <stdio.h>

// Função de ordenação Bubble Sort
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

int main() {
    int numeros[10];

    // Cadastro de números
    for (int i = 0; i < 10; ++i) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Ordenação usando Bubble Sort
    bubbleSort(numeros, 10);

    // Encontrar o menor número e sua frequência
    int menor = numeros[0];
    int contMenor = 1;
    for (int i = 1; i < 10; ++i) {
        if (numeros[i] == menor) {
            contMenor++;
        } else {
            break; 
        }
    }

    // Encontrar o maior número e sua frequência
    int maior = numeros[9];
    int contMaior = 1;
    for (int i = 8; i >= 0; --i) {
        if (numeros[i] == maior) {
            contMaior++;
        } else {
            break;
        }
    }

    // Resultados
    printf("\nMenor numero: %d\n", menor);
    printf("Frequencia que o menor numero aparece vetor: %d\n", contMenor);
    printf("Maior numero: %d\n", maior);
    printf("Frequencia que o maior numero aparece no vetor: %d\n", contMaior);

    return 0;
}
