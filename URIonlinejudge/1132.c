#include <stdio.h>

 int main (){
  int a,b, soma=0,i;
  scanf("%d %d", &a,&b);
  if(a>b){
   for(i=b; i<=a;i++){
     if(i%13!=0){
       soma+=i;
     }
   }
  }
  else if (a<b){
   for(i=a; i<=b;i++){
    if(i%13!=0){
      soma+=i;
    }
   }
  }
  else if (b==a){
    if(a%13!=0)soma+=a;
  } 
printf("%d\n", soma);
   return 0;
 }