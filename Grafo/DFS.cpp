#include <iostream>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;
class Graph{

    int V;
    list<int> *adj;

  public:
    Graph(int V);
    void adicionarAresta(int v1, int v2);
    void dfs (int V);  
};
void Graph::adicionarAresta(int v1, int v2){
  adj[v1].push_back(v2);
}

Graph::Graph(int V){
   this->V = V;
   adj = new list<int>[V];
}
void Graph::dfs(int v){
  stack<int> pilha;
      bool visitados[V];

      for(int i=0; i<V ; i++)
        visitados[i] = false;

      while(true){
        if(!visitados[v]){
          cout << "visitando o vértice " << v << "...\n";
          visitados[v] = true;
          pilha.push(v);
        }

        bool achou = false;
        list<int>::iterator it;

        for(it = adj[v].begin(); it  != adj[v].end(); it++){
            if(!visitados[*it]){
              achou = true;
              break;
            }
        }
        if(achou) v = *it;
        else{
            pilha.pop();
            if(pilha.empty())break;
            v = pilha.top();
        }
      } 
}

int main() {
  int V = 8;

  Graph grafo(V);

  grafo.adicionarAresta(0,1);
  grafo.adicionarAresta(0,2);
  grafo.adicionarAresta(1,3);
  grafo.adicionarAresta(1,4);
  grafo.adicionarAresta(2,5);
  grafo.adicionarAresta(2,6);
  grafo.adicionarAresta(6,7);

  grafo.dfs(0);


  return 0;
}