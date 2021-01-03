#include <stdio.h>

int main (){
  int entrada;
  scanf("%d", &entrada);
   
     for(int j=1; j<=entrada; j++){
       printf("%d %d %d\n", j, j*j, j*j*j);
       printf("%d %d %d\n", j, j*j+1, j*j*j+1);

     }



  return 0;
}