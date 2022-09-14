#include <stdio.h>
#include <stdlib.h>
struct indices
{
    int antes;
    int valor;
};
typedef struct indices pos;

int busca(pos *vetor, int size, int number)
{
    int esq = -1, dir = size;
    while (esq < dir - 1)
    {
        int half = (esq + dir) / 2;
        if (vetor[half].valor < number)
            esq = half;
        else
            dir = half;
    }
    if (vetor[dir].valor == number)
        return vetor[dir].antes;
    else
        return -1;
}
void ordena(pos *vetor, int size)
{
    int inicio, fim;
    pos *x;
    x = malloc(sizeof(pos));
    for (inicio = 1; inicio < size; inicio++)
    {
        x[0] = vetor[inicio];
        fim = inicio - 1;
        while (fim >= 0 && vetor[fim].valor > x[0].valor)
        {
            vetor[fim + 1] = vetor[fim];
            fim--;
        }
        vetor[fim + 1] = x[0];
    }
}

int main(void)
{
    pos *aux;
    int size, sizeArray, sizeBusca, number, flag = 0;
    scanf("%d %d", &sizeArray, &sizeBusca);
    aux = malloc(sizeArray * sizeof(pos));

    for (size = 0; size < sizeArray; size++, aux[size].antes = size)
    {
        scanf("%d", &aux[size].valor);
    }

    ordena(aux, size);

    for (int i = 0; i < sizeBusca; i++)
    {
        scanf("%d", &number);
        printf("%d\n", busca(aux, sizeArray, number));
    }
    return 0;
}