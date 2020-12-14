#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

int remove_depois (celula *p){
  if(p->prox == NULL) return 0;
  else{
    if(p->prox->prox == NULL){
        celula *ihu = p->prox;
            p->prox = NULL;
              free(ihu);
    }
    else{
        celula *ihu = p->prox;
            p->prox = ihu->prox;
              free(ihu);
    } 
  }
  return 1;
}
void remove_elemento(celula *le, int x){
    celula *ptr = le -> prox;

    if(ptr->dado==x){
        remove_depois(le);
        return;
    }
    if(ptr==NULL)return;

    while(ptr!=NULL){
        if(ptr->prox->dado==x){
          remove_depois(ptr);
          return;
        }
        ptr = ptr->prox;
    }
}
void remove_todos_elementos(celula *le, int x){
    celula *ptr = le -> prox;
    if(ptr->dado==x){
      remove_depois(le);
      return;}
    if(ptr->prox == NULL) return;
    while(ptr!=NULL){
         if(ptr->prox->dado==x)remove_depois(ptr);  
            ptr = ptr -> prox;
    }
}
int main (){


   return 0;
}