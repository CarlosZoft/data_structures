#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;
    
void insere_inicio(celula *le, int x){
    celula *ptr = malloc (sizeof (celula));
    if (ptr==NULL) exit(1);
    ptr->dado = x;
     ptr->prox = le->prox;
      le->prox = ptr;
}
void insere_final(celula *le, int x){
    celula *ptr = malloc (sizeof (celula));
    ptr->dado = x;
    ptr->prox = NULL;
    celula *aux = le;
    if (aux==NULL) {
      le=ptr;
    }
    else{
        while(aux->prox != NULL)aux = aux->prox;
          aux->prox = ptr;
    }
}
void insere_antes(celula *le, int x, int y){
    celula *ptr = malloc (sizeof (celula));
    ptr -> dado = x;
    celula *ptr1 = le -> prox; //previous
    celula *ptr2 = le -> prox -> prox;//current
    int flagOne=0;
    if (ptr1 == NULL || ptr1->dado==y){
      insere_inicio(le, x);
        exit(1);
    }
    else if(ptr2->dado==y){
           ptr1 -> prox = ptr;
             ptr -> prox = ptr2;
    }
    else if(ptr2==NULL)insere_final(le, x);
    else{
      ptr1 = ptr1 -> prox;
       ptr2 = ptr2 -> prox;

      while(ptr2!=NULL){
          if(ptr2->dado == y){
            ptr1 -> prox = ptr;
              ptr -> prox = ptr2;
                flagOne=100;
          }
          ptr1 = ptr1 -> prox;
          ptr2 = ptr2 -> prox;
      }
      if(flagOne==0){
         insere_final(le, x);
         return;
      }
    }
}