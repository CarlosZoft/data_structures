#include <stdio.h>

int main (){
  int entrada;

  scanf("%d", &entrada);
  while(entrada!=0){
  for(int i=1; i<=entrada; i++){
    if(i!=1)printf(" ");
     printf("%d", i);
  }
  printf("\n");
  scanf("%d", &entrada);
  }

  return 0;
}