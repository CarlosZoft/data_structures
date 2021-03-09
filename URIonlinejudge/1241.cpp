#include <iostream>
#include <string>

using namespace std;
int main() {
  string a,b;
  int entrada, flag = 0;
  cin >> entrada;
  while (entrada) {

    cin >> a >> b;

    if(b.length() > a.length()){
      cout << "nao encaixa" << "\n";
    }
    else{
      int aux = a.length() - 1;
      for(int i = b.length()-1; i>-1; i--){
        if(b[i]!=a[aux--]){
          cout << "nao encaixa" << "\n";
          flag = 1;
          break;
        }
      }
      if(flag == 0)cout << "encaixa" << "\n";
    }
    flag = 0;
    entrada--;
  }  
  return 0;
}