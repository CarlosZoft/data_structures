#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int size, int number)
{
    int esq = -1, dir = size;
    while (esq < dir - 1)
    {
        int half = (esq + dir) / 2;
        if (arr[half] < number)
            esq = half;
        else
            dir = half;
    }
    return dir;
}

int main(void)
{

    int *arr;
    int sizeArray, sizeSearch, number;
    scanf("%d", &sizeArray);
    arr = malloc(sizeArray * sizeof(int));
    scanf("%d", &sizeSearch);

    for(int idx = 0; idx < sizeArray; idx++)
    {
        scanf("%d", &arr[idx]);
    }

    for (int idx = 0; idx < sizeSearch; idx++)
    {
        scanf("%d", &number);
        printf("%d\n", binarySearch(arr, sizeArray, number));
    }

    return 0;
}