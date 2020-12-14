#include <stdio.h>
#include <stdlib.h>
typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *cria_pilha(){
  celula *topo = malloc(sizeof(celula));
  topo->prox = NULL;
  return topo;
}

void empilha(celula *f, int x){
    celula *ptr = malloc(sizeof(celula));
     ptr -> dado = x;
      ptr ->prox = f -> prox;
        f -> prox = ptr;
}
int desempilha (celula *f){
    celula *lixo = f -> prox;
    if(f->prox==NULL) return 0;
    int y  = lixo -> dado;
    f -> prox = lixo -> prox;
    free(lixo);
  
    return y; 
}

void imprime(celula *topo){
    celula *ptr = topo->prox;
    while(ptr != NULL){
      printf("%d ", ptr->dado);
      ptr= ptr->prox;
    }
    printf("\n");
}
int verifica(celula *le){
    celula *ptr = le ->prox;

    if(ptr!=NULL)return ptr ->dado;
    return 0;
}
int main (){
   celula *ptr = cria_pilha();
   celula *ptr1 = cria_pilha();
   unsigned int entrada, i, tam=0;
   unsigned long int v;
   int a, menor=0,b=0;
   char tipo[4];
   scanf("%d", &entrada);
   
   for(i=0; i<entrada; i++){
      scanf("%s", tipo);

      if (tipo[0]=='P' && tipo[1]=='U' && tipo[2]=='S' && tipo[3]=='H'){
          scanf("%ld", &v);
          empilha(ptr,v);
          if(menor == 0){
              menor = v;
                empilha(ptr1, v);
          } 
          else if(v<=menor){
              menor = v;
                empilha(ptr1, v);
          }         
      }
      else if (tipo[0]=='P' && tipo[1]=='O' && tipo[2]=='P'){
          a = desempilha(ptr);
          if(a==0)printf("EMPTY\n");
          else if(a==menor){
              desempilha(ptr1);
                menor = verifica(ptr1);
          }      
      }
      else if (tipo[0]=='M' && tipo[1]=='I' && tipo[2]=='N'){
          if(verifica(ptr)==0)printf("EMPTY\n");
          else {
              printf("%d\n", verifica(ptr1));
          }
      }  
   }
  return 0;
}