#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

void heapify(int *vetor, int tamanho, int i){
    int no = i;
    int esquerdo = (i * 2) + 1;
    int direito = (i * 2) + 2;
    int aux;

    if(esquerdo < tamanho && vetor[esquerdo] > vetor[no]){
        no = esquerdo;
    }
    if(direito < tamanho && vetor[direito] > vetor[no]){
        no = direito;
    }
    if(no != i){
        aux = vetor[i];
        vetor[i] = vetor[no];
        vetor[no] = aux;

        heapify(vetor, tamanho, no);
    }
}

void heap_sort(int *vetor, int tamanho){
    for(int i = (tamanho / 2) - 1; i >= 0; i--){
        heapify(vetor, tamanho, i);
    }
    for(int i = tamanho - 1; i >= 0; i--){
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;

        heapify(vetor, i, 0);
    }
}

void printar_vetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");
}

void gerar_numeros_vetor(int *vetor, int tamanho){
    for(int i = 0; i < TAMANHO; i++){
        vetor[i] = rand() % TAMANHO;
        for(int j = 0; j < TAMANHO; j++){
            if(vetor[i] == vetor[j] && i != j){
                vetor[i] = rand() % TAMANHO;
                j = -1;
            }
        }
    }
}

int main(){
    srand(time(NULL));

    int *vetor = (int*) malloc(TAMANHO * sizeof(int));

    gerar_numeros_vetor(vetor, TAMANHO);

    printf("Vetor desordenado: ");
    printar_vetor(vetor, TAMANHO);

    heap_sort(vetor, TAMANHO);
    printf("Vetor ordenado: ");
    printar_vetor(vetor, TAMANHO);

    return 0;
}