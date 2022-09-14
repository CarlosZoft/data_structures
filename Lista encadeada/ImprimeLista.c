#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void imprime(celula *le){
  celula *ptr = le->prox;
  
  while (ptr != NULL) {
    printf("%d", ptr->dado);
    printf(" -> ");
    ptr = ptr->prox;
  }
  printf("NULL\n");
}

void imprime_rec(celula *le){
  celula *ptr = le->prox;
   if(ptr!= NULL){
       printf("%d", ptr->dado);
        printf(" -> ");
          imprime_rec(ptr); 
    }
   if (ptr == NULL)printf("NULL\n"); 
}

