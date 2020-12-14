#include <stdio.h>
#include <stdlib.h>
typedef struct celula {
  char element;
  struct celula *prox;
} celula;
celula *cria_lista () {
  celula *ptr = malloc (sizeof (celula));
  ptr->prox = ptr;
  return ptr;
}
celula *enfileira (celula *fila, char x){
    celula *ptr = malloc(sizeof(celula));
    ptr -> prox = fila -> prox;
    fila->prox = ptr;
    fila -> element = x;
    return ptr;
}
int verificaValidade(celula *p, int tam){
    celula *ptr = p->prox; 
    int verP=0, verC=0, verCo=0, i=0;
    while(i<tam){
        if(ptr->element == ')')verP++;
          else if(ptr->element == '}')verC++;
             else if(ptr->element == ']')verCo++;
        if(ptr->element == '(')verP--;
          else if(ptr->element == '{')verC--;
              else if(ptr->element == '[')verCo--;
        ptr = ptr -> prox;
        i++;
    }
    if(verP==0 && verC==0 && verCo == 0)return 1;
    else return 0;
}
void imprime (celula *le) {
	celula *ptr = le->prox;
  while (ptr != NULL) {
    printf ("%c ", ptr->element);
    printf (" -> ");
    ptr = ptr->prox;
	}
	printf("NULL\n");
}

int main(void) {
    char element;
    int tam =0 ;
    celula *fila = cria_lista();
    
    
    while(scanf("%c", &element)!= '\n'){
        if(element=='(' || element == '{' || element== '[' || element ==')' || element == '}' || element ==  ']'){
          fila = enfileira(fila,element);
          tam++;
        }
        else if (element =='\n') break;  
    }


    int result = verificaValidade(fila,tam);
    if(result == 1) printf("sim\n");
    else if (result == 0) printf ("nao\n");

}