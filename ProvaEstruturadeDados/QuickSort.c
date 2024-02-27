#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int *comparisons, int *swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            (*swaps)++;
        }
    }

    swap(&arr[i + 1], &arr[high]);
    (*swaps)++;
    return i + 1;
}

void quickSort(int arr[], int low, int high, int *comparisons, int *swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);

        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
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
    int *vetorAleatorio = (int *)malloc(size * sizeof(int));

    if (vetorAleatorio == NULL) {
        perror("Erro ao alocar memoria para vetorAleatorio");
        exit(EXIT_FAILURE);
    }

    int comparisons = 0, swaps = 0;

    // Vetor aleatório
    readArrayFromFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_aleatorio_teste.txt", vetorAleatorio, size);

    printf("Desempenho para vetor aleatorio:\n");

    clock_t start = clock();
    quickSort(vetorAleatorio, 0, size - 1, &comparisons, &swaps);
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printMetrics(comparisons, swaps, cpu_time_used);

    free(vetorAleatorio);

    // Vetor ordenado
    int *vetorOrdenado = (int *)malloc(size * sizeof(int));
    readArrayFromFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_ordenado_teste.txt", vetorOrdenado, size);

    printf("\nDesempenho para vetor ordenado:\n");

    comparisons = 0;
    swaps = 0;
    start = clock();
    quickSort(vetorOrdenado, 0, size - 1, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printMetrics(comparisons, swaps, cpu_time_used);

    free(vetorOrdenado);

    // Vetor invertido
    int *vetorInvertido = (int *)malloc(size * sizeof(int));
    readArrayFromFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_invertido_teste.txt", vetorInvertido, size);

    printf("\nDesempenho para vetor invertido:\n");

    comparisons = 0;
    swaps = 0;
    start = clock();
    quickSort(vetorInvertido, 0, size - 1, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printMetrics(comparisons, swaps, cpu_time_used);

    free(vetorInvertido);

    return 0;
}
