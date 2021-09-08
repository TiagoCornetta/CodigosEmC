#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
};

struct Fila
{
    int *itens;
    int tamanho;
    int inicio;
    int fim;
};

void criafila(struct Fila *, int);
struct Item criaitem(int);
int filacheia(struct Fila);
int filavazia(struct Fila);
void colocarfila(struct Fila *,struct Item);
void mostrafila(struct Fila );
void desenfilera(struct Fila *);

int main()
{
    struct Fila fila;
    int n,chave;
    char c;
    scanf("%d",&n);
    criafila(&fila,n);

    while(scanf("\n%c",&c) != EOF)
    {
        if (c=='E')
        {
            scanf("%d",&chave);
            colocarfila(&fila,criaitem(chave));
        }
        else if(c == 'D')
        {
            desenfilera(&fila);
        }
        else // M para mostrar
        {
            mostrafila(fila);
        }
    }

    return 0;
}


void criafila(struct Fila *fila,int n)
{
    fila->itens= (int *)malloc(n*sizeof(int));
    fila->inicio=0;
    fila->fim=0;
    fila->tamanho=n;
}

struct Item criaitem(int n)
{
    struct Item it;
    it.chave=n;
    return it;
}

void colocarfila(struct Fila *fila, struct Item it)
{
    if(!filacheia(*fila))
    {
        fila->itens[fila->fim] = it.chave;
        fila->fim = (fila->fim+1)%fila->tamanho; //assim voce pega o resto da divisao por inteiro permitindo que ele fique indo e voltando
    }
}

int filacheia(struct Fila fila)
{
    return  (fila.fim+1)%fila.tamanho == fila.inicio; //se sao 3 elementos posicao 2 entao 3/3 resto 0, inicio 0 entao vdd
}

int filavazia(struct Fila fila)
{
    return fila.inicio== fila.fim;
}


void mostrafila(struct Fila fila)
{
    int i;
    for(i=fila.inicio;i!=fila.fim;i=(i+1)%fila.tamanho)
    {
        
        printf("%d%s",fila.itens[i],(i+1)%fila.tamanho!=fila.fim?" ":"\n"); 

    }

}

void desenfilera(struct Fila *fila)
{
    if(!filavazia(*fila))
    {
        printf("Item %d desenfileirado\n",fila->itens[fila->inicio]);
        fila->inicio= (fila->inicio+1)%fila->tamanho;
    }
}