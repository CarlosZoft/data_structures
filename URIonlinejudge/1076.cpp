#include <iostream>

#define v 100

using namespace std;

int adj[v][v] , verify[v], cont;

void verify1(int a, int b){
    verify[a] = 1;
    for(int i=0; i < b ; ++i){
      if(adj[a][i] == 1 && verify[i] == -1){
          cont++;
          verify1(i,b);    
      }
    }
}

int main() {
  int tests, begin, ver, are, o, w;

  cin >> tests;
  while(tests--){
    
    cin >> begin >> ver >> are;
    //zerando matriz;
    for(int i = 0; i< ver ; ++i){
      for(int j = 0; j < ver ; ++j){
          adj[i][j]=0;
      }
      verify[i] = -1;
    }
    // preenchendo;
    for(int i = 0; i < are ; ++i){
      cin >> o >> w;
      adj[o][w]=1;
      adj[w][o]=1;
    }
    verify1(begin,ver);
    cout << cont*2 << "\n";
    cont = 0;  
  }

  return 0;
}