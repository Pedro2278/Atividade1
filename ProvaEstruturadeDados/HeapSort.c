#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i, int *comparacoes, int *trocas) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    (*comparacoes)++;
    if (esquerda < n && arr[esquerda] > arr[maior]) {
        maior = esquerda;
    }

    (*comparacoes)++;
    if (direita < n && arr[direita] > arr[maior]) {
        maior = direita;
    }

    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        (*trocas)++;
        heapify(arr, n, maior, comparacoes, trocas);
    }
}

void heapSort(int arr[], int n, int *comparacoes, int *trocas) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparacoes, trocas);
    }

    for (int i = n - 1; i > 0; i--) {
        trocar(&arr[0], &arr[i]);
        (*trocas)++;
        heapify(arr, i, 0, comparacoes, trocas);
    }
}

void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void lerArrayDoArquivo(const char *nomeArquivo, int arr[], int tamanho) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < tamanho; i++) {
        if (fscanf(arquivo, "%d", &arr[i]) != 1) {
            fprintf(stderr, "Erro ao ler o arquivo ou atingiu o final inesperadamente\n");
            fclose(arquivo);
            exit(EXIT_FAILURE);
        }
    }

    fclose(arquivo);
}

void imprimirMetricas(int comparacoes, int trocas, double tempoDeExecucao) {
    printf("Comparacoes: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
    printf("Tempo de execucao: %.6f segundos\n", tempoDeExecucao);
}

int main() {
    const unsigned int tamanho = 1000; // Ajustado para mil números
    int *vetorAleatorio = (int *)malloc(tamanho * sizeof(int));

    if (vetorAleatorio == NULL) {
        perror("Erro ao alocar memoria para vetorAleatorio");
        exit(EXIT_FAILURE);
    }

    int comparacoes = 0, trocas = 0;

    // Vetor aleatório
    lerArrayDoArquivo("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_aleatorio_teste.txt", vetorAleatorio, tamanho);

    printf("Desempenho para vetor aleatorio:\n");

    clock_t inicio = clock();
    heapSort(vetorAleatorio, tamanho, &comparacoes, &trocas);
    clock_t fim = clock();
    double tempoDeExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    imprimirMetricas(comparacoes, trocas, tempoDeExecucao);

    free(vetorAleatorio);

    // Vetor ordenado
    int *vetorOrdenado = (int *)malloc(tamanho * sizeof(int));
    lerArrayDoArquivo("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_ordenado_teste.txt", vetorOrdenado, tamanho);

    printf("\nDesempenho para vetor ordenado:\n");

    comparacoes = 0;
    trocas = 0;
    inicio = clock();
    heapSort(vetorOrdenado, tamanho, &comparacoes, &trocas);
    fim = clock();
    tempoDeExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    imprimirMetricas(comparacoes, trocas, tempoDeExecucao);

    free(vetorOrdenado);

    // Vetor invertido
    int *vetorInvertido = (int *)malloc(tamanho * sizeof(int));
    lerArrayDoArquivo("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_invertido_teste.txt", vetorInvertido, tamanho);

    printf("\nDesempenho para vetor invertido:\n");

    comparacoes = 0;
    trocas = 0;
    inicio = clock();
    heapSort(vetorInvertido, tamanho, &comparacoes, &trocas);
    fim = clock();
    tempoDeExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    imprimirMetricas(comparacoes, trocas, tempoDeExecucao);

    free(vetorInvertido);

    return 0;
}
