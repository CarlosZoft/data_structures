#include <iostream>
using namespace std;
int main() {
  
  double a,b,c;
  double aux;
  cin >> a >> b >> c;
  if(c>b){
    aux = b;
    b = c;
    c = aux;
  }
  if(b>a){
    aux = a;
    a = b;
    b = aux;
  }
  if(a>=b+c){
    cout << "NAO FORMA TRIANGULO" << endl;
    return 0;
  }
  if((a*a)==(b*b)+(c*c)) cout << "TRIANGULO RETANGULO" << endl;
  if((a*a) > (b*b)+(c*c) ) cout << "TRIANGULO OBTUSANGULO" << endl;
  if((a*a) < (b*b)+(c*c) ) cout << "TRIANGULO ACUTANGULO" << endl;
  if(a==b && b==c) cout << "TRIANGULO EQUILATERO" << endl;
  if((a==b && b!=c)|| (b==c && a!=b) || (a==c && b!= a)) cout << "TRIANGULO ISOSCELES" << endl;

 return 0;
}