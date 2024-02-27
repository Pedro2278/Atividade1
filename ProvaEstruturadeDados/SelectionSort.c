#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
            (*swaps)++;
        }
    }
}

void generateOrderedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void generateInvertedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void generateRandomNumbers(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Intervalo de 0 a 999999
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
        perror("Erro ao alocar memoria para vetor Aleatorio");
        exit(EXIT_FAILURE);
    }

    int comparisons, swaps;

    // Vetor aleatório
    readArrayFromFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_aleatorio_teste.txt", vetorAleatorio, size);

    printf("Desempenho para vetor aleatorio usando Selection Sort:\n");

    clock_t start = clock();
    selectionSort(vetorAleatorio, size, &comparisons, &swaps);
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comparacoes: %d\n", comparisons);
    printf("Trocas: %d\n", swaps);
    printf("Tempo de execucao: %.6f segundos\n", cpu_time_used);

    free(vetorAleatorio);

    // Vetor ordenado
    int *vetorOrdenado = (int *)malloc(size * sizeof(int));
    readArrayFromFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_ordenado_teste.txt", vetorOrdenado, size);

    printf("\nDesempenho para vetor ordenado usando Selection Sort:\n");

    start = clock();
    selectionSort(vetorOrdenado, size, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comparacoes: %d\n", comparisons);
    printf("Trocas: %d\n", swaps);
    printf("Tempo de execucao: %.6f segundos\n", cpu_time_used);

    free(vetorOrdenado);

    // Vetor invertido
    int *vetorInvertido = (int *)malloc(size * sizeof(int));
    readArrayFromFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_invertido_teste.txt", vetorInvertido, size);

    printf("\nDesempenho para vetor invertido usando Selection Sort:\n");

    start = clock();
    selectionSort(vetorInvertido, size, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comparacoes: %d\n", comparisons);
    printf("Trocas: %d\n", swaps);
    printf("Tempo de execucao: %.6f segundos\n", cpu_time_used);

    free(vetorInvertido);

    return 0;
}
