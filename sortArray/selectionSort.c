#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define exch(A,B) {int temp = A; A = B; B = temp;}

int main () {

  int arr[1000];
  
  int elementsLength = 0;
  while(scanf("%d", &arr[elementsLength]) != EOF) elementsLength++;

  //sort
  for(int l = 0; l < elementsLength - 1; l++){
    int min = l;
    
    for(int j = l+1; j < elementsLength ; j++){
      if(less(arr[j], arr[min])){
        min = j;
      }
    }
    exch(arr[min], arr[l]);
  };
  
  //output
  for(int out = 0; out < elementsLength ; out++)
    (!out) ? 
    printf("%d", arr[out]) :
    printf(" %d", arr[out]);
  
  printf("\n");

  return 0;
}