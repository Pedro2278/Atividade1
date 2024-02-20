#include <stdio.h>
#include <string.h>

// Armazenar os dados do aluno
struct Aluno {
    char nome[50];
    float nota1;
    float nota2;
    float mediaPonderada;
};

// Função para ordenação Bubble Sort (média ponderada)
void bubbleSortMedia(struct Aluno arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].mediaPonderada < arr[j + 1].mediaPonderada) {
                // Troca
                struct Aluno temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função de ordenação Bubble Sort nota 1
void bubbleSortNota1(struct Aluno arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].nota1 > arr[j + 1].nota1) {
                // Troca
                struct Aluno temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Aluno alunos[8];

    // Cadastro dos alunos
    for (int i = 0; i < 8; ++i) {
        printf("Digite o nome do aluno  %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;  // Remover o caractere de nova linha

        char buffer[50];

        // Leitura da nota 1
        do {
            printf("Digite a (nota 1) do aluno %d: ", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
        } while (sscanf(buffer, "%f", &alunos[i].nota1) != 1 || alunos[i].nota1 < 0 || alunos[i].nota1 > 10);

        // Leitura da nota 2
        do {
            printf("Digite a (nota 2) do aluno %d: ", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
        } while (sscanf(buffer, "%f", &alunos[i].nota2) != 1 || alunos[i].nota2 < 0 || alunos[i].nota2 > 10);

        // Calcular média ponderada
        alunos[i].mediaPonderada = (2 * alunos[i].nota1 + 3 * alunos[i].nota2) / 5;
    }

    // Ordenar por média ponderada (decrescente)
    bubbleSortMedia(alunos, 8);

    // Listar todos os alunos ordenados por média ponderada
    printf("\nAlunos ordenados por media ponderada:\n");
    for (int i = 0; i < 8; ++i) {
        printf("%s - Media Ponderada: %.2f\n", alunos[i].nome, alunos[i].mediaPonderada);
    }

    // Ordenar por nota 1 (crescente)
    bubbleSortNota1(alunos, 8);

    // Listar todos os alunos ordenados por nota 1
    printf("\nAlunos ordenados por nota 1:\n");
    for (int i = 0; i < 8; ++i) {
        printf("%s - Nota 1: %.2f\n", alunos[i].nome, alunos[i].nota1);
    }

    // Listar alunos reprovados em ordem alfabética
    printf("\nAlunos reprovados (media < 7) em ordem alfabetica:\n");
    for (int i = 0; i < 8; ++i) {
        if (alunos[i].mediaPonderada < 7) {
            printf("%s - Media Ponderada: %.2f\n", alunos[i].nome, alunos[i].mediaPonderada);
        }
    }

    return 0;
}
