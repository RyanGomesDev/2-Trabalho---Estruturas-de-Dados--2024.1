#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int* criar_vetor(int tam){
	int *vetor = (int *)malloc(tam * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < tam; i++) {
        vetor[i] = rand() % 1000;
    }

    return vetor;
}

int* copiar_vetor(int *v, int tam){
	int *vetorCopia = (int *)malloc(tam * sizeof(int));
	
	for (int i = 0; i < tam; i++) {
        vetorCopia[i] = v[i];
    }
    
    return vetorCopia;
}

void imprimir_vetor(int *v, int tam){
	printf("Impressão do Vetor:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubbleSort(int *v, int tam){
	int i, j, temp;
    for (i = 0; i < tam-1; i++) {
        for (j = 0; j < tam-i-1; j++) {
            if (v[j] > v[j+1]) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

void insertionSort(int *v, int tam) {
    int i, j, chave;
    for (i = 1; i < tam; i++) {
        chave = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = chave;
    }
}

void quickSort(int *v, int tam){
	if(tam>1){
		int x = v[0];
		int a = 1; 
		int b = tam-1;
		while(1){
			while(a < tam && v[a] <= x){
				a++;
			}
			while(v[b] > x){
				b--;
			}
			if(a<b){
				int temp = v[a];
				v[a] = v[b];
				v[b] = temp;
				a++;
				b--;
			}else{
				break;
			}
 		}
		v[0] = v[b];
		v[b] = x;
		quickSort(v, b);
		quickSort(&v[a], tam-a);
 	}
}

void mergeSort(int *v, int tam) {
	mergeSort_ordena(v, 0, tam-1);
}

void mergeSort_ordena(int *v, int esq, int dir) {
	if (esq == dir){
		return;
	}
	int meio = (esq + dir) / 2;
	mergeSort_ordena(v, esq, meio);
	mergeSort_ordena(v, meio+1, dir);
	mergeSort_intercala(v, esq, meio, dir);
	return;
}

void mergeSort_intercala(int *v, int esq, int meio, int dir){
	int i, j, k;
	int a_tam = meio-esq+1;
	int b_tam = dir-meio;
	int *a = (int*) malloc(sizeof(int) * a_tam);
	int *b = (int*) malloc(sizeof(int) * b_tam);

	for (i = 0; i < a_tam; i++){
		a[i] = v[i+esq];
	}
	for (i = 0; i < b_tam; i++){
		b[i] = v[i+meio+1];
	}

	for (i = 0, j = 0, k = esq; k <= dir; k++) {
		if (i == a_tam){
			v[k] = b[j++];
		} else if (j == b_tam){
			v[k] = a[i++];
		} else if (a[i] < b[j]){
			v[k] = a[i++];
		} else{
			v[k] = b[j++];
		}
	}
	free(a); 
	free(b);
}

void heapify(int *v, int tam, int i) {
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if (esquerda < tam && v[esquerda] > v[maior]) {
        maior = esquerda;
    }

    if (direita < tam && v[direita] > v[maior]) {
        maior = direita;
    }

    if (maior != i) {
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;

        heapify(v, tam, maior);
    }
}

void heapSort(int *v, int tam) {
    for (int i = tam / 2 - 1; i >= 0; i--) {
        heapify(v, tam, i);
    }

    for (int i = tam - 1; i >= 0; i--) {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        heapify(v, i, 0);
    }
}
