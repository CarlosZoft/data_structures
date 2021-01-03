#include <iostream> 

using namespace std;

int main (){
    int entrada_cod, numero, aux, cont=0;
      cin >> entrada_cod;
    while(entrada_cod!=0){
        cin >> numero;
        aux=numero;
        while(numero!=0){
         
          if(aux%numero==0){
           cont++;
          }
          numero--;
    }
    if(cont==2)cout << aux << " eh primo" << endl;
    else cout << aux << " nao eh primo" << endl;
      cont=0;
      entrada_cod--;
    }
    return 0;
}