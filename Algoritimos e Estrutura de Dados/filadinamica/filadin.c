#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;//novo numero que está vindo
    struct Item *proximo; 
};


struct Fila
{
    struct Item *inicio; //estamos trabalhando com endereços
    struct Item *fim; //estamos trabalhando com endereços
};

struct Fila *criafila();
struct Item *criaitem(int);
int filavazia(struct Fila *);
void enfileirar(struct Fila *,struct Item *);
void mostrafila(struct Fila *);
struct Item *desinfilera(struct Fila *);

int main()
{
    struct Fila *fila=criafila();
    struct Item *item;
    char c;
    int chave;

    while(scanf("\n%c",&c) != EOF)
    {
        if(c == 'E')
        {
            scanf("%d",&chave);
            enfileirar(fila,criaitem(chave));
        }
        else if(c == 'D')
        {
            item=desinfilera(fila);
            if(item!=NULL)
            {
                printf("Item %d desinfelerado\n",item->chave);
                free(item );
            }
        }
        else //Mostrar a fila
        {
            mostrafila(fila);
        }

    }

    return 0;
}



struct Fila *criafila()
{
    struct Fila *it= (struct Fila *)malloc(sizeof(struct Fila));//para criar uma fila
    if(it!=NULL)
    {    
        it->inicio=NULL; //inicialmente apontando para nada
        it->fim=NULL; //incialmente apontando para nada 
    }
    return it;
}


struct Item *criaitem(int n)
{
    struct Item *it= (struct Item *)malloc(sizeof(struct Item));
    if(it!=NULL)
    {
        it->chave=n;// o endereço que esta entrando possui o numero
        it->proximo=NULL;// e ele apontando para nada pois sera o ultimo termo
    }
    return it;
}


void enfileirar(struct Fila *fila,struct Item *novo)
{
    
    if(filavazia(fila))
    {
        fila->inicio= novo;//o inicio aponta para o primeiro item e o final é nulo
    }
    else
    {
        fila->fim->proximo= novo;
    }
    fila->fim=novo;
}




//se os dois não apontam para nada quer dizer que tem alguem dentro da fila
int filavazia(struct Fila *fila) 
{
    return fila->inicio==NULL && fila->fim==NULL; 
}

void mostrafila(struct Fila *fila)
{
    struct Item *it= fila->inicio;
    while(it!=NULL)
    {
        printf("%d%s",it->chave,it->proximo!=NULL?" ":"\n");
        it = it->proximo;
    }

}


struct Item *desinfilera(struct Fila *fila)
{
    struct Item *it=fila->inicio;
    if(!filavazia(fila))
    {
        fila->inicio=fila->inicio->proximo;
        if(fila->inicio==NULL)
        {
            fila->fim=NULL;
        }

    }
    return it;
}