#include <stdlib.h>
#include <stdio.h>



struct Item
{
    int chave;
    struct Item *anterior;
};

struct Pilha
{
    struct Item *topo;
};

struct Item *criaitem(int);
struct Pilha *criapilha();
void empilhar(struct Pilha *,struct Item *);
int pilhavazia(struct Pilha *);
void topoprabase(struct Pilha *);
struct Item *desinfelerar(struct Pilha *);
void baseprotopo(struct Pilha *);

int main()
{
    int chave;
    struct Pilha *pilha=criapilha();
    char c;
    struct Item *it;
    
    while(scanf("\n%c",&c) != EOF)
    {
        if(c=='E') //enserir o item 
        {
            scanf("%d",&chave);
            empilhar(pilha,criaitem(chave));

        }
        else if(c=='D') //remover o item
        {
            it= desinfelerar(pilha);
            if(it!=NULL)
            {
                printf("Item %d desempilhado\n",it->chave);
                free(it);
            }
        }
        else if (c=='T') //topo para base
        {
            topoprabase(pilha);
        }
        else //base para o topo
        {
            baseprotopo(pilha);
        }


    }
    return 0;
}



struct Item *criaitem(int novo)
{
    struct Item *item=(struct Item*)malloc(sizeof(struct Item));
    if(item!=NULL)
    {
        item->chave=novo;
        item->anterior=NULL;
    } 
    return item;
}

struct Pilha *criapilha()
{
    struct Pilha *it=(struct Pilha *)malloc(sizeof(struct Pilha));
    if(it!=NULL)
    {
        it->topo=NULL;
    }
    return it;
}


void empilhar(struct Pilha *pilha,struct Item *novo)
{
    novo->anterior=pilha->topo;
    pilha->topo=novo;
}

int pilhavazia(struct Pilha *pilha)
{
    return pilha->topo==NULL;
}


void topoprabase(struct Pilha *pilha)
{
    struct Item *novo=pilha->topo;
    while(novo!=NULL)
    {
        printf("%d%s",novo->chave,novo->anterior!=NULL?" ":"\n");
        novo=novo->anterior;
    }


}


struct Item *desinfelerar(struct Pilha *pilha)
{
    struct Item *it=pilha->topo;
    if(!pilhavazia(pilha))
    {
        pilha->topo=pilha->topo->anterior;
    }
    return it;
}

void baseprotopo(struct Pilha *pilha)
{
    struct Pilha *Pilha2 = criapilha();
    struct Item *it=pilha->topo;
    
    while(it!=NULL)
    {
        empilhar(Pilha2,criaitem(it->chave));
        it=it->anterior;
    }
    
    while(!pilhavazia(Pilha2))
    {
        it = desinfelerar(Pilha2);
        printf("%d%s", it->chave, !pilhavazia(Pilha2)?" ":"\n");
        free(it);
    }
    free(Pilha2);
}

