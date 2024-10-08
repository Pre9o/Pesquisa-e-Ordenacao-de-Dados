#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

void bogo_sort(int *vetor, int tamanho){
    int ordenado = 0;
    while(!ordenado){
        ordenado = 1;
        for(int i = 0; i < tamanho - 1; i++){
            if(vetor[i] > vetor[i + 1]){
                ordenado = 0;
                break;
            }
        }

        if(!ordenado){
            for(int i = 0; i < tamanho; i++){
                int aux = vetor[i];
                int posicao = rand() % tamanho;
                vetor[i] = vetor[posicao];
                vetor[posicao] = aux;
            }
        }
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

    bogo_sort(vetor, TAMANHO);
    printf("Vetor ordenado: ");
    printar_vetor(vetor, TAMANHO);

    return 0;
}