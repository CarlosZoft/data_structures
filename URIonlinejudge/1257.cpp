#include <iostream>
#include <string>
using namespace std;

int main(void){
  int test,qtd,sum=0;
  string mtz[100];

  cin>>test;

  while(test){
    cin >> qtd;
    for(int i=0 ;i < qtd;i++){
        cin>>mtz[i];
    }
    for(int i=0;i < qtd;i++){
      int tam = mtz[i].length();
      for(int j=0 ; j < tam;j++){
        sum+=(mtz[i][j]-65)+i+j;
      }
    }
    cout << sum << endl;
    //mtz.clear();
    sum = 0;
    test--;
  }
  return 0;
}