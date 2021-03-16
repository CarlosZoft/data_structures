#include <iostream>
#include <list>
#include <queue> 

using namespace std;

class Grafo
{
	int V; 
	list<int> *adj; 

public:
	Grafo(int V); 
	void adicionarAresta(int v1, int v2); 

	void bfs(int v);
};

Grafo::Grafo(int V)
{
	this->V = V; 
	adj = new list<int>[V]; 

void Grafo::adicionarAresta(int v1, int v2)
{
	adj[v1].push_back(v2);
}

void Grafo::bfs(int v)
{
	queue<int> fila;
	bool visitados[V]; 

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	cout << "Visitando vertice " << v << " ...\n";
	visitados[v] = true;

	while(true)
	{
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				cout << "Visitando vertice " << *it << " ...\n";
				visitados[*it] = true; 
				fila.push(*it); 
			}
		}

		
		if(!fila.empty())
		{
			v = fila.front();
			fila.pop();
		}
		else
			break;
	}
}

int main()
{
	int V = 8;

	Grafo grafo(V);

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(2, 5);
	grafo.adicionarAresta(2, 6);
	grafo.adicionarAresta(6, 7);

	grafo.bfs(0);

	return 0;
}