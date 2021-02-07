#include <iostream>
#include <stdio.h>

using namespace std;

int verify (int matriz[9][9]) {
  int cont=0, cont1=0,cont3=0;
    for(int i =0; i<9; i++){
      cont=cont1= 0;
      for(int j=0; j<9; j++){
        cont+=matriz[i][j];
        cont1+=matriz[j][i];
      }
      if(cont!=45)return 0;
      if(cont1!=45)return 0;
    }
    for(int i=1; i<9 ; i+=3){
      for(int j=1; j<9 ; j+=3){
        cont3=0;
            if(i-1<0 || j-1<0)continue;
            for(int k=i-1; k<i+2; k++){
              for(int h=j-1; h<j+2; h++){
                cont3+=matriz[k][h];
              }
            }    
            if(cont3!=45)return 0;  
      }
    }
    
   for(int k = 1; k<=9; k++){
    for(int i =0; i<9; i++){
      cont = cont1 = 0;
      for(int j=0; j<9; j++){
        if(matriz[i][j]==k)cont++;
        if(matriz[j][i]==k)cont1++; 
      }
      if(cont!=1 || cont1!=1)return 0;
    }
   }     
  return 1;
}


int main() {
  int entrada;
  int matriz[9][9];
  cin >> entrada;
  int aux = entrada;
  while(entrada--){
    for(int i=0; i<9; i++){
      for(int j=0; j<9;j++){
        scanf("%d", &matriz[i][j]);
      }
    }
    printf("Instancia %d\n", aux-entrada);

  (verify(matriz)) ? cout << "SIM" <<endl <<endl : cout << "NAO" << endl << endl;
  }


  return 0;
}