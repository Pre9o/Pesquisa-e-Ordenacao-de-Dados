#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

void shellsort(int *vetor, int tamanho){
    int i, j, intervalo, aux;

    intervalo = tamanho / 2;

    do{
        for(i = intervalo; i < tamanho; i++){
            aux = vetor[i];
            j = i - intervalo;

            while(j >= 0 && aux < vetor[j]){
                vetor[j + intervalo] = vetor[j];
                j -= intervalo;
            }
            vetor[j + intervalo] = aux;
        }
        intervalo /= 2;
    }while(intervalo > 0);
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

    int *vetor = (int *) malloc(TAMANHO * sizeof(int));

    gerar_numeros_vetor(vetor, TAMANHO);

    printf("Vetor desordenado: ");
    printar_vetor(vetor, TAMANHO);

    shellsort(vetor, TAMANHO);
    printf("Vetor ordenado:    ");
    printar_vetor(vetor, TAMANHO);

    return 0;
}
