#include <stdlib.h>
#include <stdio.h>


struct Item
{
    int chave; //o numero que sera inserido 
};

struct Fila
{
    int *itens;
    int inicio;
    int fim;
    int tamanho;
};

void criafila(struct Fila *,int);
struct Item criaitem(int); //criar a chave
void mostrafila(struct Fila);
void inseriritem(struct Fila *,struct Item);
void removeitem(struct Fila *);
int filavazia(struct Fila);
int filacheia(struct Fila);




int main()
{
    struct Fila fila;
    int n,chave;
    scanf("%d",&n);
    criafila(&fila,n);
    char c;
    while(scanf("\n%c",&c) != EOF)
    {
        if(c == 'E') //inserir o item
        {
            scanf("%d",&chave); //le o numero que eu vou inserir na lista
            inseriritem(&fila,criaitem(chave));//vai inserir a chave na lista
        }

        else if(c== 'R') //remover o item
        {
            if(!filavazia(fila))printf("Item %d removido\n",fila.itens[fila.inicio]);
            
            removeitem(&fila);

        }

        else //para mostrar a lista, no caso seria M
        {
            mostrafila(fila);
        }


    }




    return 0;
}






void criafila(struct Fila *fila,int n)
{
    fila->itens= (int *)malloc(n*sizeof(int));
    fila->inicio=-1;
    fila->fim=-1;
    fila->tamanho=n;
}


struct Item criaitem(int n)
{
    struct Item it;
    it.chave = n;
    return it;
}


void mostrafila(struct Fila  fila)
{
    int i;
    if(!filavazia(fila))
    {   
        for(i=fila.inicio;i<=fila.fim;i++)
        {
            printf("%d%s",fila.itens[i],i<fila.fim?" ":"\n");
        }
    }
}

void inseriritem(struct Fila *fila,struct Item it)
{
    if(!filacheia(*fila))
    {
        if(filavazia(*fila))
        {
            fila->inicio++;
        }
        fila->fim ++;
        fila->itens[fila->fim]= it.chave;
    }

}

int filacheia(struct Fila fila)
{
    return  fila.fim == fila.tamanho-1;
}

int filavazia(struct Fila fila)
{
    return (fila.inicio == -1 && fila.fim == -1) || (fila.inicio > fila.fim);
}


void removeitem(struct Fila *fila)
{
    if(!filavazia(*fila))
    {
       if(fila->inicio!= fila->fim) 
        {
            fila->inicio++;
        }
       else
       {
           fila->inicio=-1;
           fila->fim=-1;
       } 
    }
}