#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#define TAMANHO 1000000

double calcularTempo(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000; // Convertendo para milissegundos
}

int main(void){
    int *vetorBubble = criar_vetor(TAMANHO);
    int *vetorInsertion = copiar_vetor(vetorBubble, TAMANHO);
    int *vetorQuick = copiar_vetor(vetorBubble, TAMANHO);
    int *vetorMerge = copiar_vetor(vetorBubble, TAMANHO);
    int *vetorHeap = copiar_vetor(vetorBubble, TAMANHO);
    
    clock_t inicio, fim;
	double tempoBubble, tempoInsertion, tempoQuick, tempoMerge, tempoHeap;
	
	// Medindo o tempo para o BubbleSort
    inicio = clock();
    bubbleSort(vetorBubble, TAMANHO);
    fim = clock();
    tempoBubble = calcularTempo(inicio, fim);

    // Medindo o tempo para o InsertionSort
    inicio = clock();
    insertionSort(vetorInsertion, TAMANHO);
    fim = clock();
    tempoInsertion = calcularTempo(inicio, fim);
    
    // Medindo o tempo para o QuickSort
    inicio = clock();
    quickSort(vetorQuick, TAMANHO);
    fim = clock();
    tempoQuick = calcularTempo(inicio, fim);
    
    // Medindo o tempo para o MergeSort
    inicio = clock();
    mergeSort(vetorMerge, TAMANHO);
    fim = clock();
    tempoMerge = calcularTempo(inicio, fim);
    
    // Medindo o tempo para o HeapSort
    inicio = clock();
    heapSort(vetorHeap, TAMANHO);
    fim = clock();
    tempoHeap = calcularTempo(inicio, fim);
	
    // Exibe os tempos de execução
    printf("Tempo de execução do BubbleSort: %.6f ms\n", tempoBubble);
    printf("Tempo de execução do InsertionSort: %.6f ms\n", tempoInsertion);
    printf("Tempo de execução do QuickSort: %.6f ms\n", tempoQuick);
    printf("Tempo de execução do MergeSort: %.6f ms\n", tempoMerge);
    printf("Tempo de execução do HeapSort: %.6f ms\n", tempoHeap);

    // Libera a memória alocada
    free(vetorBubble);
    free(vetorInsertion);
    free(vetorQuick);
    free(vetorMerge);
    free(vetorHeap);

    return 0;
}
