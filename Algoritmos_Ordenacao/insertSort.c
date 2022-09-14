#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define exch(A,B) {int temp = A; A = B; B = temp;}
#define cmpexch(A,B){if(less(A,B))exch(A,B);}

void insertionSort(int *arr, int l, int r){
  for(int i = r-1; i > l; i--){
    cmpexch(arr[i], arr[i - 1]);
  }
  for(int i = l + 2; i < r ; i++){
    int j = i;
    int tmp = arr[j];
    while(less(tmp, arr[j - 1])){
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
} 


int main () {

  int arr[50000];
  
  int i = 0;
  while(scanf("%d", &arr[i]) != EOF)i++;
  
  //sort
  insertionSort(arr, 0, i);

  //output
  for(int out = 0; out < i ; out++)
    (!out) ? 
    printf("%d", arr[out]) :
    printf(" %d", arr[out]);
  
  printf("\n");

  return 0;
}