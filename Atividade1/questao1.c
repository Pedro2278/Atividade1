#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Funcionario {
    char nome[50];
    float salario;
};

// Função para comparar dois funcionários por salário (crescente)
int compararPorSalarioCrescente(const void *a, const void *b) {
    return ((struct Funcionario *)a)->salario - ((struct Funcionario *)b)->salario;
}

// Função para comparar dois funcionários por salário (decrescente)
int compararPorSalarioDecrescente(const void *a, const void *b) {
    return ((struct Funcionario *)b)->salario - ((struct Funcionario *)a)->salario;
}

// Função para comparar dois funcionários por nome (ordem alfabética)
int compararPorNome(const void *a, const void *b) {
    return strcmp(((struct Funcionario *)a)->nome, ((struct Funcionario *)b)->nome);
}

// Bubble Sort 
void bubbleSort(struct Funcionario *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].salario > arr[j + 1].salario) {
                // Troca
                struct Funcionario temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort 
void insertionSort(struct Funcionario *arr, int n) {
    int i, j;
    struct Funcionario key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move os elementos maiores que key para frente da posição atual
        while (j >= 0 && arr[j].salario < key.salario) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort 
void selectionSort(struct Funcionario *arr, int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            // Procura o menor elemento
            if (strcmp(arr[j].nome, arr[minIndex].nome) < 0) {
                minIndex = j;
            }
        }
        // Troca
        struct Funcionario temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    // Criar um array de funcionários
    struct Funcionario funcionarios[5];

    // Cadastro de dados dos funcionários
    for (int i = 0; i < 5; ++i) {
        printf("Digite o nome do funcionario %d: ", i + 1);
        scanf("%s", funcionarios[i].nome);
        printf("Digite o salario do funcionario %d: ", i + 1);
        scanf("%f", &funcionarios[i].salario);
    }

    // Bubble Sort por salário (crescente)
    bubbleSort(funcionarios, 5);
    printf("\nFuncionarios em ordem crescente de salario (Bubble Sort):\n");
    for (int i = 0; i < 5; ++i) {
        printf("%s: R$ %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
    }

    // Insertion Sort por salário (decrescente)
    insertionSort(funcionarios, 5);
    printf("\nFuncionarios em ordem decrescente de salario (Insertion Sort):\n");
    for (int i = 0; i < 5; ++i) {
        printf("%s: R$ %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
    }

    // Selection Sort por nome (ordem alfabética)
    selectionSort(funcionarios, 5);
    printf("\nFuncionarios em ordem alfabetica (Selection Sort):\n");
    for (int i = 0; i < 5; ++i) {
        printf("%s: R$ %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
    }

    return 0;
}
