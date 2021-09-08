#include <stdio.h>
#include <stdlib.h>


struct Item
{
    int chave;
    struct Item *proximo;
    struct Item *anterior;
};

struct Lista
{
    struct Item *inicio,*fim;
};

struct Lista *crialista();
struct Item *criaitem(int);
void inserir(struct Lista *,struct Item *);
struct Item *busca(struct Lista *,int );
void mostralista(struct Lista *);
struct Item *remover(struct Lista *,int);
int listavazia(struct Lista *);
void mostralistainv(struct Lista *);

int main()
{
    struct Lista *lista;
    lista=crialista();
    struct Item *it;//utilizado como auxiliar para ajudar nas operancoes de busca e remocao
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
            it=busca(lista,chave);
            if(it!=NULL)printf("item %d localizado na lista\n",chave);
            else printf("item %d nao localizado na lista\n",chave);
            free(it);
        }
        else if (c=='P')
        {
            mostralista(lista);
        }
        else//U
        {
           mostralistainv(lista);     
        }
    }

    return 0;
}


struct Lista *crialista()
{
    struct Lista *lista;
    lista=(struct Lista *)malloc(sizeof(struct Lista));
    if(lista!=NULL)
    {
        lista->inicio=NULL;  
        lista->fim=NULL;
    }  
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
        it->anterior=NULL;
    }
    return it; 
}


void inserir(struct Lista *lista,struct Item *item)
{
    struct Item *atual=lista->inicio;
    int aux=0;//para dizer quando acho a posicao
    while(atual !=NULL && aux==0)
    {
        if(atual->chave < item->chave)
        {
            atual=atual->proximo;
        }
        else
        {
            aux=1;
        }
    }
    //lista com numeros no meio ou comeco
    if(atual !=NULL)
    {
        //caso base
        item->anterior=atual->anterior;
        item->proximo=atual;
        //INSERIR NO MEIO
        if(atual->anterior!=NULL)
        {
            atual->anterior->proximo=item;
        }
        else
        {
            lista->inicio=item;
        }
        atual->anterior=item;
    }
    //inicio lista vazia
    else if(listavazia(lista))
    {
        lista->inicio=item;
        lista->fim=item;
    }
    //final da lista
    else
    {
        lista->fim->proximo=item;
        item->anterior=lista->fim;
        lista->fim=item;
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
    struct Item *atual=busca(lista,n);        
    
    if(atual!=NULL)
    {
        //removendo o primeiro
        if(atual->anterior==NULL)
        {
                atual->proximo->anterior=atual->anterior;
                lista->inicio=atual->proximo;
        }
        else//removendo meio ou fim
        {
            
            if(atual->proximo==NULL)//removendo fim
            {
                atual->anterior->proximo=atual->proximo;
                lista->fim=atual->anterior;
            }
            else //removendo do meio
            {
                atual->anterior->proximo=atual->proximo;
                atual->proximo->anterior=atual->anterior;
            }
        }
        
    }
    return atual;
    
}


int listavazia(struct Lista *lista)
{
    return lista->inicio==NULL && lista->fim==NULL;
}


void mostralistainv(struct Lista *lista)
{   
    struct Item *it=lista->fim;
    while(it!=NULL)
    {
        printf("%d%s",it->chave,it->anterior!=NULL?" ":"\n");
        it=it->anterior;
    }
}