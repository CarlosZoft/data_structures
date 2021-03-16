#include <stdio.h>
#include <stdlib.h>

typedef struct no
{ // Arvóre
    int dado;
    struct no *esq, *dir;
} no;

typedef struct reg
{
    no *conteudo;
    struct reg *prox;
} celula;

celula *pi;

void criapilha(void)
{
    pi = malloc(sizeof(celula)); // cabeça
    pi->prox = NULL;
}

void empilha(no *y)
{
    if (pi == NULL)
        return;
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = y;
    nova->prox = pi->prox;
    pi->prox = nova;
}

no *desempilha(void)
{
    celula *p;
    p = pi->prox;
    no *x = p->conteudo;
    pi->prox = p->prox;
    free(p);
    return x;
}

int pilhavazia()
{
    if (pi->prox == NULL)
        return 1;
    else
        return 0;
}

void liberapilha()
{
    no *x;
    while (!pilhavazia())
    {
        x = desempilha();
    }
    free(x);
}

void em_ordem(no *raiz)
{
    criapilha();

    empilha(raiz);

    no *x;

    int i = 0;
    while (1)
    {
        x = desempilha();
        if (x != NULL)
        {
            empilha(x);
            empilha(x->esq);
        }
        else
        {

            if (pilhavazia())
            {
                //printf("entrou no if pilha\n");
                break;
            }
            //printf("entrou aqui porra\n");
            x = desempilha();
            i++;
            if (i == 1)
                printf("%d", x->dado);
            else
                printf(" %d", x->dado);
            empilha(x->dir);
        }
    }
    printf("\n");
}
no *criar_arvore(int x, no *esq, no *dir)
{
  no *raiz = malloc(sizeof(no));
  raiz->dado = x;
  raiz->esq = esq;
  raiz->dir = dir;
  return raiz;
}
no *procurar(no *raiz, int x)
{
  if (raiz == NULL || raiz->dado == x)
    return raiz;
  no *esq = procurar(raiz->esq, x);
  if (esq != NULL)
    return esq;
  return procurar(raiz->dir, x);
}

void inserir(no *raiz, int x, int y, char L)
{
  // inserir x do lado L de y
  no *procurado = procurar(raiz, y);
  if (L == 'E')
  {
    no *novo = criar_arvore(x, procurado->esq, NULL);
    procurado->esq = novo;
  }
  else
  {
    no *novo = criar_arvore(x, NULL, procurado->dir);
    procurado->dir = novo;
  }
}

int main()
{
  int elem, novo;
  char lado;
  // printf ("Digite a raiz: ");
  scanf("%d", &novo);
  no *raiz = criar_arvore(novo, NULL, NULL);
  // printf ("Digite NOVO LADO EXISTENTE: ");
  while (scanf("%d %c %d", &novo, &lado, &elem) != EOF)
  {
    inserir(raiz, novo, elem, lado);
    // printf ("Digite NOVO LADO EXISTENTE: ");
  }

  printf("Ordem: ");
  em_ordem(raiz);

  return 0;
}