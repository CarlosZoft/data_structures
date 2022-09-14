#include <stdio.h>
#include <stdlib.h>

int busca(int *vetor, int size, int number)
{
    int esq = -1, dir = size;
    while (esq < dir - 1)
    {
        int half = (esq + dir) / 2;
        if (vetor[half] < number)
            esq = half;
        else
            dir = half;
    }
    return dir;
}

void ordenacao(int a, int v[1001])
{
    a -= 1;
    int sub;
    while (a)
    {
        for (int i = 0; i < a; i++)
        {
            if (v[i] > v[i + 1])
            {
                sub = v[i];
                v[i] = v[i + 1]; //novo menor
                v[i + 1] = sub;  //novo maior
            }
        }
        a--;
    }
}

int main(void)
{

    int *vetor;
    int size = 0, sizeArray, sizeBusca, number;
    scanf("%d", &sizeArray);
    vetor = malloc(sizeArray * sizeof(int));
    scanf("%d", &sizeBusca);
    while (size != sizeArray)
    {
        scanf("%d", &vetor[size]);
        size++;
    }

    for (int i = 0; i < sizeBusca; i++)
    {
        scanf("%d", &number);
        printf("%d\n", busca(vetor, sizeArray, number));
    }

    return 0;
}