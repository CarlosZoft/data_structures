#include <stdio.h>

void sort(int size, int arr[1001])
{
    int temp;
    while (size)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1]; //novo menor
                arr[i + 1] = temp;  //novo maior
            }
        }
        size--;
    }
}

int main(void)
{

    int arr[1001], size = 0;

    while (scanf("%d", &arr[size]) != EOF) size++;
    
    sort(size - 1, arr);
    for (int i = 0; i < size; i++)
    {
        (i != size - 1) ? printf("%d ", arr[i]) : printf("%d\n", arr[i]);
    }

    return 0;
}