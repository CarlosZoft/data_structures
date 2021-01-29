#include <iostream>
 using namespace std;
int main() {
  int ball, A, L, P;
  cin >> ball >> A >> L >> P;

  if(ball <= A && ball <=L && ball <=P)
    cout <<"S" << endl;
  else 
    cout <<"N" << endl;

}