#include <stdio.h>

int main (){
 int entrada, i;
 int vetor[100];
 scanf("%d", &entrada);
 vetor[0]=0;
 vetor[1]=1;
 for(i=0;i<entrada;i++){
    if(i!=0)printf(" ");
    if(i>=2){
        vetor[i]=vetor[i-1]+vetor[i-2];
        printf("%d", vetor[i]);
    }
    else printf("%d",vetor[i]);
 }
 printf("\n");
 
  return 0;
}