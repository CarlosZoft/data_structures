#include <stdio.h>
#include <stdlib.h>
typedef long long int Item;

#define Key(A)(A)
#define less(A,B) (Key(A)<Key(B))
#define lesseq(A,B) (Key(A)<=Key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

int separa(Item *arr, int left, int right){
    Item elementRight = arr[right];
    int indexElement = left;
    for(int i = left ; i < right ;i++)
        if(lesseq(arr[i], elementRight)){
          exch(arr[i],arr[indexElement]);
          indexElement++;
        }
            
    exch(arr[indexElement], arr[right]);
    return indexElement;
}

void quickSortM3(Item *arr, int left, int right){
    int j;
    if(right <= left) return;
    cmpexch(arr[(right + left) / 2],arr[right]);
    cmpexch(arr[left],arr[(right + left) / 2]);
    cmpexch(arr[right],arr[(right + left) / 2]);

    j = separa(arr, left, right);
    quickSortM3(arr, left, j-1);
    quickSortM3(arr, j+1, right);
}

int main () {
  int arrayIntegerLength;
  scanf("%d", &arrayIntegerLength);

  Item *arrayInteger = malloc(sizeof(Item) * (arrayIntegerLength + 1));

  for(int i = 0; i < arrayIntegerLength; i++)
    scanf("%lld", &arrayInteger[i]);
  
  quickSortM3(arrayInteger, 0, arrayIntegerLength - 1);

  for(int i = 0; i < arrayIntegerLength; i++)
    (i != arrayIntegerLength - 1) ? 
      printf("%lld ", arrayInteger[i]) :
      printf("%lld\n", arrayInteger[i]);

  return 0;
}