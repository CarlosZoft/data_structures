#include <stdio.h>


typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){
   celula *ptr = l->prox;
   celula *ptr1 = l1;
   celula *ptr2 = l2;
   int x;
      while(ptr != NULL){
          x = ptr->dado;
         if(x%2!=0){
                  ptr1-> prox = ptr;
                  ptr1 = ptr1-> prox;
         }  
         else{
                  ptr2-> prox = ptr; 
                  ptr2 = ptr2-> prox;
                 
         }
         ptr = ptr -> prox;
      }
   ptr1 ->prox = NULL;
   ptr2 ->prox = NULL;     
}