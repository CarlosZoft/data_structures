#include <stdio.h>

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

    int vetor[1001], size = 0;

    while (scanf("%d", &vetor[size]) != EOF)
    {
        size++;
    }
    ordenacao(size, vetor);
    for (int i = 0; i < size; i++)
    {
        (i != size - 1) ? printf("%d ", vetor[i]) : printf("%d\n", vetor[i]);
    }

    return 0;
}