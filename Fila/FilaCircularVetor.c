#include <stdio.h>
#include <stdlib.h>

typedef struct {
int *v; // Vetor que representa a fila
int N; // Tamanho da fila
int inicio, fim; // Indicadores de inicio e final da fila
} fila;

int enfileira (fila *f, int x){
    int a;
    if(f -> inicio % (f -> N) == ((f -> fim + 2) % (f -> N))){
       f -> fim = ((f -> fim + 1) % f -> N);
       return 1;
    }
    else{
        f -> v[f -> fim] = x;
        f -> fim = ((f -> fim + 1) % f -> N);
        return 0;
    } 
}

int desenfileira (fila *f, int *y){
    if(((f -> inicio + 1) % (f -> N)) == f -> fim % (f -> N)){
        return 0;
    }
    else{
        *y = f -> v[f -> inicio];
        f -> v[f -> inicio] = NULL;
        f -> inicio = ((f -> inicio + 1) % (f -> N));
        return 1;
    }
}