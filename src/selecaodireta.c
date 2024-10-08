#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

void selecao_direta(int *vetor, int tamanho){
    int i, j, min, aux;

    for(i = 0; i < TAMANHO - 1; i++){
        min = i;

        for(j = i + 1; j < TAMANHO; j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        if(i != min){
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
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

    int *vetor = (int *) malloc(TAMANHO * sizeof(int));

    gerar_numeros_vetor(vetor, TAMANHO);

    printf("Vetor desordenado: ");
    printar_vetor(vetor, TAMANHO);

    selecao_direta(vetor, TAMANHO);
    printf("Vetor ordenado: ");
    printar_vetor(vetor, TAMANHO);

    return 0;
}