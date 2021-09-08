#include <stdio.h>
#include <stdlib.h>


struct Heap
{
    int *itens;
    int qt;
    int total;
};

struct Heap criaheap(int);
int filhoesquerda(int);
int filhodireita(int);
int ultimopai(int);
void inserir(struct Heap *,int);
void geraheap(struct Heap *);
void peneirar(struct Heap *,int);
int removeHeap(struct Heap *);

int main()
{
    int n,aux,i;
    char c;
    struct Heap h;
    scanf("%d",&n);
    h= criaheap(n);
    
    while(scanf("\n%c",&c) != EOF)
    {
        if(c== 'I')
        {
            scanf("%d",&aux);
            inserir(&h,aux);
        }
        else if(c =='R')
        {
            if(h.qt>0)
            {
                int aux1;
                aux1=removeHeap(&h);
                printf("%d\n",aux1);
            }
        }
        else if(c =='M')
        {
            int i;
            for(i=0;i<h.qt;i++)
            {
                printf("%d%s", h.itens[i], i < h.qt-1 ? " " : "\n");
            }
        }
    }

    return 0;

}


struct Heap criaheap(int n)
{
    struct Heap aux;
    aux.itens = (int *)malloc(n*(sizeof(int)));
    aux.qt=0;
    aux.total=n;
    return aux;
}


int ultimopai(int n)
{
  return (n/2)-1;
}

int filhoesquerda(int n)
{
  return n*2+1;
}

int filhodireita(int n)
{
  return n*2+2;
}

void inserir(struct Heap *h, int aux)
{
    if(h->total > h->qt)
    {
        h->itens[h->qt]=aux;
        h->qt+=1;
        geraheap(h);
    }
}


void geraheap(struct Heap *h)
{
    int i;
    for(i =ultimopai(h->qt);i>=0;i--)
    {
        peneirar(h,i);
    }

}

void peneirar(struct Heap *h,int p)
{
    int iMaior=p, aux;

    if(filhodireita(p)< h->qt  && h->itens[filhodireita(p)] < h->itens[iMaior])
    {
        iMaior= filhodireita(p);
    }

    if(filhoesquerda(p)< h->qt  && h->itens[filhoesquerda(p)] < h->itens[iMaior])
    {
        iMaior= filhoesquerda(p);
    }
   
    if(iMaior!=p)
    {
        aux = h->itens[p];
        h->itens[p] = h->itens[iMaior];
        h->itens[iMaior]=aux;
        peneirar(h,iMaior);
    }
}


int removeHeap(struct Heap *h)
{
    int aux3,rem;
    if(h->qt>0)
    {
        rem = h->itens[0];
        aux3 = h->itens[0];
        h->itens[0] = h->itens[h->qt -1];
        h->itens[h->qt-1] = aux3;
        h->qt--;
        peneirar(h,0);
    }
    return rem;
}