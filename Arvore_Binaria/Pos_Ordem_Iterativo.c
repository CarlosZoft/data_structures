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

celula *cria_pilha()
{
    celula *topo = malloc(sizeof(celula));
    topo->prox = NULL;
    return topo;
}
void empilha(celula *p, no *x)
{
    celula *ptr = malloc(sizeof(p));
    ptr->conteudo = x;
    ptr->prox = p->prox;
    p->prox = ptr;
}

no *desempilha(celula *p)
{
    celula *lixo = p->prox;
    no *y = lixo->conteudo;
    p->prox = lixo->prox;
    free(lixo);
    return y;
}

no *pilhaVazia(celula *p)
{
    if (p->prox == NULL)
        return NULL;
    else
        return p->prox->conteudo;
}
void pos_ordem(no *raiz)
{
    celula *pilha = cria_pilha();
    if (raiz == NULL)
        return;
    int i = 0;
    do
    {
        while (raiz)
        {
            if (raiz->dir)
                empilha(pilha, raiz->dir);
            empilha(pilha, raiz);
            raiz = raiz->esq;
        }

        raiz = desempilha(pilha);
        if (raiz->dir && pilhaVazia(pilha) == raiz->dir)
        {
            desempilha(pilha);
            empilha(pilha, raiz);
            raiz = raiz->dir;
        }
        else
        {
            if (i == 0)
                printf("%d", raiz->dado);
            else
                printf(" %d", raiz->dado);
            i = 1;
            raiz = NULL;
        }
    } while (pilhaVazia(pilha) != NULL);
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

    printf("Pós-ordem: ");
    pos_ordem(raiz);

    return 0;
}
