#include <stdio.h>

int main (){
  int A, N, cont=0, i=1, aux;

  scanf("%d %d", &A,&N);
  while(N<=A){
    scanf("%d", &N);
  }
  aux=A;
  while(aux<=N){
    aux+=A+i;
        i++;
  }
  
  printf("%d\n", i);
  return 0;
}