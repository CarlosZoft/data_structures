#include <stdio.h>

 int main (){
  int entrada=0, cont1=1, cont2=2, cont3=3;
  scanf("%d", &entrada);
 for(int i=0; i<entrada; i++){
    printf("%d %d %d PUM\n",cont1,cont2,cont3);
    cont1+=4;
        cont2+=4;
            cont3+=4;
 }
   return 0;
}