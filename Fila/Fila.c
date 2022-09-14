#include <stdio.h>
#include <stdlib.h>
 
typedef struct celula {
  int dado;
  struct celula *prox;
} celula;


void enfileira (celula **f, int x){
    celula *ptr = malloc(sizeof(celula));
    ptr ->prox = (*f) -> prox;
    (*f) -> prox = ptr;
    (*f) -> dado = x;
    *f = ptr;
}




int desenfileira (celula *f, int *y){
    celula *lixo = f -> prox;

    if(lixo == f) return 0;

    *y  = lixo -> dado;
    f -> prox = lixo -> prox;
    free(lixo);
    
    return 1; 
}