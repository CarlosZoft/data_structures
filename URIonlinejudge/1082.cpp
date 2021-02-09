#include <iostream>
#include <stdio.h>

#define max 10000

using namespace std;

int aux[max];
int node, vizinhos[100][100];
int componentes;

void way(int i) {
    aux[i] = 1;
    for (int j = 0; j < node; ++j)if(vizinhos[i][j] == 1 && aux[j] == -1)way(j);
}

void verify() {
    for (int i = 0; i < node; ++i)aux[i] = -1;
    
    for (int i = 0; i < node; ++i) {
        if (aux[i] == -1) {
            cout << "\n";
            componentes++;
            way(i);
            for (int j = 0; j < node; j++) {
                if (aux[j] > 0)   {
                    cout << char ('a'+j) <<",";
                    aux[j]=0;
                }
            }
        }
    }
}

int main() {
    char v,w;
    int casos,edge;
    cin >> casos;
    for(int i = 0; i < casos; i++) {

        cin >> node >> edge;

        for (int j=0; j<node; j++)
          for (int k=0; k<node; k++) 
            vizinhos[j][k]=0;
            
        for (int j=0; j < edge; j++) {
            cin >> v >> w;
            vizinhos[v-97][w-97]=1;
            vizinhos[w-97][v-97]=1;
        }
        componentes=0;
        cout << "Case #" << (i+1) << ":";
        verify();
        cout <<endl<<componentes<<" connected components\n\n";
    }
    return 0;
}