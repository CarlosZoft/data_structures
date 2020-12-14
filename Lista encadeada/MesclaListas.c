#include <stdio.h>


typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
   celula *ptr1 = l1->prox;
   celula *ptr2 = l2->prox;
   celula *ptr = l3;
   while(ptr1 != NULL && ptr2 != NULL){
      if((ptr1->dado)<=(ptr2->dado)){
             ptr->prox = ptr1;
               ptr1 = ptr1 ->prox; 
      }
      else { 
             ptr->prox = ptr2;
               ptr2 = ptr2 ->prox;   
      }      
      ptr = ptr -> prox;
   }
   
   if(ptr1==NULL && ptr2!=NULL){
             ptr->prox = ptr2;
    }
    else if(ptr2==NULL && ptr1!=NULL){
      
                ptr->prox = ptr1;
           
    }

   ptr = NULL; 

}