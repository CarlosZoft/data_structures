#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define exch(A,B) {int temp = A; A = B; B = temp;}

int main () {

  int v[1000];
  
  int i = 0;
  while(scanf("%d", &v[i]) != EOF)i++;

  //sort
  for(int l = 0; l < i - 1; l++){
    int min = l;
    
    for(int j = l+1; j < i ; j++){
      if(less(v[j], v[min])){
        min = j;
      }
    }
    exch(v[min], v[l]);
  };
  
  //output
  for(int out = 0; out < i ; out++)
    (!out) ? 
    printf("%d", v[out]) :
    printf(" %d", v[out]);
  
  printf("\n");

  return 0;
}