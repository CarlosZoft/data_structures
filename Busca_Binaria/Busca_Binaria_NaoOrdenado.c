#include <stdio.h>
#include <stdlib.h>
struct indices
{
    int before;
    int value;
};
typedef struct indices pos;

int binarySearch(pos *arr, int size, int number)
{
    int esq = -1, dir = size;
    while (esq < dir - 1)
    {
        int half = (esq + dir) / 2;
        if (arr[half].value < number)
            esq = half;
        else
            dir = half;
    }
    if (arr[dir].value == number)
        return arr[dir].before;
    else
        return -1;
}
void sort(pos *arr, int size)
{
    int start, end;
    pos *x;
    x = malloc(sizeof(pos));
    for (start = 1; start < size; start++)
    {
        x[0] = arr[start];
        end = start - 1;
        while (end >= 0 && arr[end].value > x[0].value)
        {
            arr[end + 1] = arr[end];
            end--;
        }
        arr[end + 1] = x[0];
    }
}

int main(void)
{
    pos *aux;
    int size, sizeArray, sizeSearch, number, flag = 0;
    scanf("%d %d", &sizeArray, &sizeSearch);
    aux = malloc(sizeArray * sizeof(pos));

    for (size = 0; size < sizeArray; size++, aux[size].before = size)
    {
        scanf("%d", &aux[size].value);
    }

    sort(aux, size);

    for (int i = 0; i < sizeSearch; i++)
    {
        scanf("%d", &number);
        printf("%d\n", binarySearch(aux, sizeArray, number));
    }
    return 0;
}