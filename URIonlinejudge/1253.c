#include <stdio.h>
int tamanho(char str[1000]){
  int i=0;
  while(str[i]!='\0'){
   i++;
  }
  return i;

}
void copia(char str[100], char str1[100]){
int i;
int tamanho1= tamanho(str);
for(i=0; i<tamanho1; i++){
  str1[i]=str[i];
}
}

int main (){
  int entradas, a, i=0;
  char frase[1000];
  scanf("%d", &entradas);
  while(entradas != 0){
     scanf(" %[^\n]",frase);
     scanf("%d", &a);
     if(a > 26){
       a%=26;
     }
    i=0;
    while(frase[i]!='\0'){

     if(frase[i]>= 65 && frase[i] <= 90){
       frase[i]-=a; 
     }
     if(frase[i]<'A'){
       frase[i]+=26;
     }
    i++;
    }
  printf("%s\n",frase);
    entradas--;
    frase[0]='\0';
  }

  return 0;
}