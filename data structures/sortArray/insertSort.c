#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define exch(A,B) {int temp = A; A = B; B = temp;}
#define cmpexch(A,B){if(less(A,B))exch(A,B);}

void insertionSort(int *v, int l, int r){
  for(int i = r-1; i > l; i--){
    cmpexch(v[i], v[i - 1]);
  }
  for(int i = l + 2; i < r ; i++){
    int j = i;
    int tmp = v[j];
    while(less(tmp, v[j - 1])){
      v[j] = v[j - 1];
      j--;
    }
    v[j] = tmp;
  }
} 


int main () {

  int v[50000];
  
  int i = 0;
  while(scanf("%d", &v[i]) != EOF)i++;
  
  //sort
  insertionSort(v, 0, i);

  //output
  for(int out = 0; out < i ; out++)
    (!out) ? 
    printf("%d", v[out]) :
    printf(" %d", v[out]);
  
  printf("\n");

  return 0;
}