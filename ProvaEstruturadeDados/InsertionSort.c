#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;

    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        (*comparisons)++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*comparisons)++;
            (*swaps)++;
        }
        arr[j + 1] = key;
    }
}

void printMetrics(int comparisons, int swaps, double cpu_time_used) {
    printf("Comparacoes: %d\n", comparisons);
    printf("Trocas: %d\n", swaps);
    printf("Tempo de execucao: %.6f segundos\n", cpu_time_used);
}

void readArrayFromFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            fprintf(stderr, "Erro ao ler o arquivo ou atingiu o final inesperadamente\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

int main() {
    const unsigned int size = 1000; // Ajustado para mil números

    // Vetor aleatório
    int *vetorAleatorio = (int *)malloc(size * sizeof(int));
    readArrayFromFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_aleatorio_teste.txt", vetorAleatorio, size);

    printf("Desempenho para vetor aleatorio:\n");

    int comparisons, swaps;
    clock_t start = clock();
    insertionSort(vetorAleatorio, size, &comparisons, &swaps);
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printMetrics(comparisons, swaps, cpu_time_used);

    free(vetorAleatorio);

    // Vetor ordenado
    int *vetorOrdenado = (int *)malloc(size * sizeof(int));
    readArrayFromFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_ordenado_teste.txt", vetorOrdenado, size);

    printf("\nDesempenho para vetor ordenado:\n");

    start = clock();
    insertionSort(vetorOrdenado, size, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printMetrics(comparisons, swaps, cpu_time_used);

    free(vetorOrdenado);

    // Vetor invertido
    int *vetorInvertido = (int *)malloc(size * sizeof(int));
    readArrayFromFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_invertido_teste.txt", vetorInvertido, size);

    printf("\nDesempenho para vetor invertido:\n");

    start = clock();
    insertionSort(vetorInvertido, size, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printMetrics(comparisons, swaps, cpu_time_used);

    free(vetorInvertido);

    return 0;
}
