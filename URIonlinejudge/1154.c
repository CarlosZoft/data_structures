#include <stdio.h>

int main (){
 double entrada;
 double cont=0, soma=0;
 scanf("%lf", &entrada);
 while(entrada>=0){
   soma+=entrada;
   cont++;
   scanf("%lf", &entrada);
 }
 printf("%.2lf\n",soma/cont);
  return 0;
}