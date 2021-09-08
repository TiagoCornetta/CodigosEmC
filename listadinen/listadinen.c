#include <stdio.h>
#include <stdlib.h>


struct Item
{
    int chave;
    struct Item *proximo;
};

struct Lista
{
    struct Item *inicio;
};

struct Lista *crialista();
struct Item *criaitem(int);
void inserir(struct Lista *,struct Item *);
struct Item *busca(struct Lista *,int );
void mostralista(struct Lista *);
struct Item *remover(struct Lista *,int);


int main()
{
    struct Lista *lista;
    lista=crialista();
    struct Item *it;//utilizado como auxiliar para ajudar nas operancoes de busca e remocao
    struct Item *auxbusca;
    int i,chave;
    char c;
    while(scanf("\n%c",&c)!=EOF)
    {
        if(c=='I')
        {
            scanf("%d",&chave);
            inserir(lista,criaitem(chave));
        }
        else if(c=='R')
        {
            scanf("%d",&chave);
            it=remover(lista,chave);
            if(it!=NULL)
            {
                printf("Item %d removido da lista\n",chave);
                free(it);
            }               
        }
        else if(c=='B')
        {
            scanf("%d",&chave);
            auxbusca=busca(lista,chave);
            if(auxbusca!=NULL)printf("SIM\n");
            else printf("NAO\n");
        }
        else //L
        {
            mostralista(lista);
        }
    }

    return 0;
}


struct Lista *crialista()
{
    struct Lista *lista;
    lista=(struct Lista *)malloc(sizeof(struct Lista));
    if(lista!=NULL)lista->inicio=NULL;    
    return lista;
}

struct Item *criaitem(int n)
{
    struct Item *it;
    it=(struct Item*)malloc(sizeof(struct Item));
    if(it!=NULL)
    {    
        it->chave=n;
        it->proximo=NULL;
    }
    return it; 
}


void inserir(struct Lista *lista,struct Item *item)
{
    struct Item *anterior=NULL;
    struct Item *atual=lista->inicio;
    int aux=0;//para dizer quando acho a posicao
    if(busca(lista,item->chave)==NULL)
    {    
        while(atual !=NULL && aux==0)
        {
            if(atual->chave < item->chave)
            {
                anterior=atual;
                atual=atual->proximo;
            }
            else
            {
                aux=1;
            }
        }
        if(anterior==NULL)//inserindo no comeco
            {
                lista->inicio=item;
            }
        else 
            {
                anterior->proximo=item;
            }
        item->proximo=atual;
    }
}

struct Item *busca(struct Lista *lista,int n)
{
    struct Item *it=lista->inicio;
    while(it!=NULL && it->chave<n)
    {
        if(n>it->chave)
        {
            it=it->proximo;
        }
    }
    if(it!=NULL)
    {
        if(it->chave==n)return it;
    }
  
    return NULL;
}

void mostralista(struct Lista *lista)
{
    struct Item *it=lista->inicio;
    if(it!=NULL)
    {
        while(it!=NULL)
        {
            printf("%d%s",it->chave,it->proximo!=NULL?" ":"\n");
            it=it->proximo;
        }
    }
}

struct Item *remover(struct Lista *lista,int n)
{
    struct Item *atual=lista->inicio;
    struct Item *anterior=NULL;
        
    while(atual!=NULL && atual->chave<n)
        {
                anterior=atual;
                atual=atual->proximo;
        }
    
    if(atual!=NULL)
    {
        if(atual->chave==n)
        {
            if(anterior==NULL)
            {
                lista->inicio=atual->proximo;
            }            
            else
            {
                anterior->proximo=atual->proximo;
            }
        
        }
        else atual= NULL;
        
    }
    
    return atual;
    
}

