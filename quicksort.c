#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

int particao(int inicio, int fim, int *vetor){
    int posicao_pivo, pivo, aux;

    posicao_pivo = ((inicio + fim) / 2);
    pivo = vetor[posicao_pivo];

    int i = inicio;
    int j = fim;

    while(i <= j){
        while(vetor[i] < pivo && i < fim){
            i++;
        }
        while(vetor[j] > pivo && j > inicio){
            j--;
        }
        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(int inicio, int fim, int *vetor){
    if(inicio == fim){
        return;
    }

    int pivo = particao(inicio, fim, vetor);
    quicksort(inicio, pivo - 1, vetor);
    quicksort(pivo, fim, vetor);
}

void printar_vetor(int *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
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

    int *vetor = (int *) malloc(TAMANHO * sizeof(int));

    gerar_numeros_vetor(vetor, TAMANHO);

    printf("Vetor desordenado: ");
    printar_vetor(vetor, TAMANHO);

    quicksort(0, TAMANHO - 1, vetor);
    printf("Vetor ordenado: ");
    printar_vetor(vetor, TAMANHO);

    return 0;
}