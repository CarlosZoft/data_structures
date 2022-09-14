#include <stdio.h>
#include <stdlib.h>
typedef long long int Item;

#define Key(A)(A)
#define less(A,B) (Key(A)<Key(B))
#define lesseq(A,B) (Key(A)<=Key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

int separa(Item *V, int l, int r){
    Item elementRight = V[r];
    int indexElement = l;
    for(int i=l ; i<r ;i++)
        if(lesseq(V[i], elementRight)){
          exch(V[i],V[indexElement]);
          indexElement++;
        }
            
    exch(V[indexElement], V[r]);
    return indexElement;
}

void quickSortM3(Item *V, int l, int r){
    int j;
    if(r<=l) return;
    cmpexch(V[(r+l)/2],V[r]);
    cmpexch(V[l],V[(r+l)/2]);
    cmpexch(V[r],V[(r+l)/2]);

    j = separa(V,l,r);
    quickSortM3(V,l,j-1);
    quickSortM3(V,j+1,r);
}

int main () {
  int lengthArrayInteger;
  scanf("%d", &lengthArrayInteger);

  Item *arrayInteger = malloc(sizeof(Item) * (lengthArrayInteger + 1));

  for(int i = 0; i < lengthArrayInteger; i++)
    scanf("%lld", &arrayInteger[i]);
  
  quickSortM3(arrayInteger, 0, lengthArrayInteger-1);

  for(int i = 0; i < lengthArrayInteger; i++)
    (i != lengthArrayInteger - 1) ? 
      printf("%lld ", arrayInteger[i]) :
      printf("%lld\n", arrayInteger[i]);

  return 0;
}