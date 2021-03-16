#include <stdio.h>
#include <stdlib.h>
typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    celula *ptr = le;
    while(ptr != NULL && ptr->dado != x){
        ptr = ptr -> prox;
    }
    return ptr;
}

celula *busca_rec (celula *le, int x){
   celula *ptr = le->prox;
   if(ptr == NULL) return NULL;
   if(ptr -> dado == x) return ptr;
   busca_rec(ptr,x);
}