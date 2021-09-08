#include <stdio.h>
#include <stdlib.h>


struct Item
{
    int chave;
};

struct Pilha
{
    int *itens;
    int tamanho;
    int topo;
};


struct Item criaitem(int);
struct Pilha criapilha(int);
void empilhar(struct Pilha *, struct Item);
int pilhavazia(struct Pilha);
int pilhacheia(struct Pilha);
void desimpilhar(struct Pilha *);
void topo(struct Pilha);
void base(struct Pilha);

int main()
{
    char c;
    int i,chave,n;
    struct Pilha pilha;
    scanf("%d",&n);
    pilha=criapilha(n);
    
    
    while(scanf("\n%c",&c)!=EOF)
    {
        if(c== 'E')//empilhar 
        {
            scanf("%d",&chave);
            empilhar(&pilha,criaitem(chave));
        }
        else if(c=='D')//desimpilhar 
        {
            desimpilhar(&pilha);
        }
        else if(c=='B')//mostrar baseprotopo
        {   
            base(pilha);
        }
        else//mostrar topo pra base
        {
            topo(pilha);
        }
    }
    
    return 0;
}


struct Pilha criapilha(int n)
{
    struct Pilha p;
    p.itens=(int *)malloc(n*sizeof(int));
    p.tamanho=n;
    p.topo=-1;
    return p;
}

struct Item criaitem(int n)
{
    struct Item it;
    it.chave=n;
    return it;
}



void empilhar(struct Pilha *pilha, struct Item item)
{
    if(!pilhacheia(*pilha))
    {
        pilha->topo+=1;
        pilha->itens[pilha->topo]=item.chave;
    }
}

int pilhavazia(struct Pilha pilha)
{
    return pilha.topo==-1;
}

int pilhacheia(struct Pilha pilha)
{
    return pilha.topo==pilha.tamanho-1;
}

void desimpilhar(struct Pilha *pilha)
{
    int aux;
    if(!pilhavazia(*pilha))
    {
        aux=pilha->itens[pilha->topo];
        pilha->topo--;
        printf("Item %d desenpilhado\n", aux);    
    }
}


void base(struct Pilha pilha)
{
    int i;
    if(!pilhavazia(pilha))
    {
        for(i=0;i<=pilha.topo;i++)
        {
            printf("%d%s",pilha.itens[i],i<pilha.topo?" ":"\n");
        }

    }
}

void topo(struct Pilha pilha)
{
    if(!pilhavazia(pilha))
    {
        int i;
        for(i=pilha.topo;i>=0;i--)
        {
            printf("%d%s",pilha.itens[i],i>0?" ":"\n");

        }
    }
}