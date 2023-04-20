#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

void bubble_sort(int *vetor, int tamanho){
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j<TAMANHO-1; j++){
            if(vetor[j] > vetor[j+1]){
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
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
        vetor[i] = rand() % 10;
        for(int j = 0; j < TAMANHO; j++){
            if(vetor[i] == vetor[j] && i != j){
                vetor[i] = rand() % 10;
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

    bubble_sort(vetor, TAMANHO);
    printf("Vetor ordenado: ");
    printar_vetor(vetor, TAMANHO);

    return 0;
}