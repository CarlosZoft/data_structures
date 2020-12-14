#include <stdio.h>
int tamanhoString(char frase[1000])
{
  int tam = 0;

  while (frase[tam] != '\0')
  {
    tam++;
  }

  return tam;
}
void removeCaracter(char frase[1000], int pos)
{
  int i;
  int tam = tamanhoString(frase);

  for (i = pos; i < tam; i++)
  {
    frase[i] = frase[i + 1];
  }
}
int main()
{
  char frase[1000][80];
  int linha = 0;
  int coluna = 0, pinto = 0;
  while (pinto != 1)
  {
    scanf("%c", &frase[linha][coluna]);
    if (frase[linha][coluna] == '\n')
    {
      //printf("entrou no if\n");
      frase[linha][coluna] = '\0';
      pinto = 1;
    }
    else if (frase[linha][coluna] == ' ')
    {
      //printf("entrou no if 2\n");
      frase[linha][coluna] = '\0';
      linha++;
      coluna = 0;
    }
    else
    {
      coluna++;
    }
  }

  int tam;
  int cont;
  for (int aux = 0; aux <= linha; aux++)
  {
    cont = 0;
    tam = tamanhoString(frase[aux]);
    for (coluna = 0; coluna < tam; coluna++)
    {
      if (coluna == 0)
      {
        removeCaracter(frase[aux], coluna);
        cont++;
      }
      else
      {
        removeCaracter(frase[aux], cont);
        cont++;
      }
    }
  }

  for (int palavra = 0; palavra <= linha; palavra++)
  {
    if (palavra == linha)
    {
      printf("%s", frase[palavra]);
    }
    else
    {
      printf("%s ", frase[palavra]);
    }
  }
  printf("\n");
  return 0;
}