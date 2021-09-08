#include <stdio.h>
#include <stdlib.h>


struct Heap
{
    int *elementos;
    int qt;
};

int ultimopai(int);
int filhoEsquerda(int);
int filhoDireita(int);
struct Heap cria(int);
void arrumar (struct Heap *);
void peneirar(struct Heap *,int);


int main()
{
    int i,n=1;
    struct Heap h;
    
    while(n!=0)
    {
        scanf("%d",&n);
        h= cria(n);

        for(i=0;i<h.qt;i++)
        {
            scanf("%d",&h.elementos[i]);
        }

        arrumar(&h);

        for(i=0;i<h.qt;i++)
        {
            printf("%d%s",h.elementos[i], i<h.qt-1?" ":"\n");
        }
        free(h.elementos);
    }
}


struct Heap cria(int n)
{
    struct Heap aux;
    aux.elementos=(int *)malloc(n*(sizeof(int)));
    aux.qt=n;
    return aux;
}


int ultimopai(int n)
{
    return (n/2)-1;
}


int filhoDireita(int n)
{
    return 2*n+2;
}

int filhoEsquerda(int n)
{
    return 2*n+1;
}

void arrumar(struct Heap *h)
{
    int i;
    for(i= ultimopai(h->qt);i>=0;i--)
    {
        peneirar(h,i);
    }
}

void peneirar(struct Heap *h,int p)
{
    int iMaior=p, aux;

    if(filhoDireita(p)< h->qt  && h->elementos[filhoDireita(p)] > h->elementos[iMaior])
    {
        iMaior= filhoDireita(p);
    }

    if(filhoEsquerda(p)< h->qt  && h->elementos[filhoEsquerda(p)] > h->elementos[iMaior])
    {
        iMaior= filhoEsquerda(p);
    }
   
    if(iMaior!=p)
    {
        aux = h->elementos[p];
        h->elementos[p] = h->elementos[iMaior];
        h->elementos[iMaior]=aux;
        peneirar(h,iMaior);
    }
}