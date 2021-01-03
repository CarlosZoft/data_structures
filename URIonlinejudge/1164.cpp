#include <iostream>

using namespace std;

int main (){
  int a, fon=0,  entrada;
  cin >> entrada;
  while(entrada!=0){
  cin >> a;

  for(int i=1; i<=(a/2); i++){
    if(a%i==0){
    fon+=i; 
    }
  
  }
  if(fon==a){
    cout << a << " eh perfeito" << endl;
  }
  else {
      cout << a << " nao eh perfeito" << endl;
  }
  fon=0;
  entrada--;
  }
    return 0;
}