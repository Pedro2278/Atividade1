#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r, int *comparisons, int *swaps) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criando arrays temporários
    int L[n1], R[n2];

    // Copiando dados para arrays temporários 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclando os arrays temporários de volta
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            (*swaps)++;
        }
        k++;
    }

    // Copiando os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal para ordenar um array usando o Merge Sort
void mergeSort(int arr[], int l, int r, int *comparisons, int *swaps) {
    if (l < r) {
        // Encontrando o ponto médio do array
        int m = l + (r - l) / 2;

        // Ordenando a primeira e a segunda metade
        mergeSort(arr, l, m, comparisons, swaps);
        mergeSort(arr, m + 1, r, comparisons, swaps);

        // Mesclando as metades ordenadas
        merge(arr, l, m, r, comparisons, swaps);
    }
}

// Função para imprimir um array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Função para gerar números aleatórios não repetidos
void generateRandomNumbers(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; 
    }
}

// Função para ler e processar o arquivo
void processFile(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
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

    int comparisons = 0, swaps = 0;

    // Vetor aleatório
    processFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_aleatorio_teste.txt", vetorAleatorio, size);

    printf("Desempenho para vetor aleatorio:\n");

    clock_t start = clock();
    mergeSort(vetorAleatorio, 0, size - 1, &comparisons, &swaps);
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comparacoes: %d\n", comparisons);
    printf("Trocas: %d\n", swaps);
    printf("Tempo de execucao: %.6f segundos\n", cpu_time_used);

    free(vetorAleatorio);

    // Vetor ordenado
    int *vetorOrdenado = (int *)malloc(size * sizeof(int));
    processFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_ordenado_teste.txt", vetorOrdenado, size);

    printf("\nDesempenho para vetor ordenado:\n");

    start = clock();
    mergeSort(vetorOrdenado, 0, size - 1, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comparacoes: %d\n", comparisons);
    printf("Trocas: %d\n", swaps);
    printf("Tempo de execucao: %.6f segundos\n", cpu_time_used);

    free(vetorOrdenado);

    // Vetor invertido
    int *vetorInvertido = (int *)malloc(size * sizeof(int));
    processFile("C:\\Users\\pm920\\Documents\\Curso ADS 2024\\Estrutura de dados II\\vetor_invertido_teste.txt", vetorInvertido, size);

    printf("\nDesempenho para vetor invertido:\n");

    start = clock();
    mergeSort(vetorInvertido, 0, size - 1, &comparisons, &swaps);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comparacoes: %d\n", comparisons);
    printf("Trocas: %d\n", swaps);
    printf("Tempo de execucao: %.6f segundos\n", cpu_time_used);

    free(vetorInvertido);

    return 0;
}
