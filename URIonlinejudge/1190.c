#include <stdio.h>

int main()
{
    double matriz[12][12], sum = 0;
    char escolha;
    int aux = 10, aux1 = 1, aux2 = 11;
    scanf("%c", &escolha);

    //preencher matriz
    for (int lin = 0; lin < 12; lin++)
    {
        for (int col = 0; col < 12; col++)
        {
            scanf("%lf", &matriz[lin][col]);
        }
    }

    //Soma matriz
    while (aux2 > 6)
    {
        int col = aux2;
        for (int lin = aux1; lin <= aux; lin++)
        {
            sum += matriz[lin][col];
        }
        aux2--;
        aux--;
        aux1++;
    }
    if (escolha == 'S')
        printf("%.1lf\n", sum);
    else if (escolha == 'M')
        printf("%.1lf\n", sum / 30);

    return 0;
}