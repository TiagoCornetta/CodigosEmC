#include <stdio.h>
#include <stdlib.h>


struct Lista
{
    int *itens; //alocar os itens na lista
    int qt;  //ver quantos itens já possuo na lista
    int tamanho; //ver o tamanho total da lista
};

struct Item
{
    int chave; //o numero que sera inserido 
};

void crialista(struct Lista *,int); //para gerar a lista que eu vou utilizar
void inseriritem(struct Lista *,struct Item); //inserir item na lista
struct Item criaitem(int); //criar a chave
int listacheia(struct Lista); //ver se a lista esta cheia
void mostralista(struct Lista);
int buscalista(struct Lista, struct Item);
int removeitem(struct Lista *,struct Item);

int main()
{
    struct Lista lista;
    int n,chave,h; //para dar o tamanho da fila
    char c; // para a operação a ser seguida
    scanf("%d",&n);
    crialista(&lista,n);
    while(scanf("\n%c",&c) != EOF)
    {
        if(c == 'I') //inserir o item
        {
            scanf("%d",&chave); //le o numero que eu vou inserir na lista
            inseriritem(&lista,criaitem(chave));//vai inserir a chave na lista
        }

        else if(c== 'R') //remover o item
        {
            scanf("%d",&chave);
            h=removeitem(&lista,criaitem(chave));
            if(h!=-1)
            {
                printf("Item %d removido\n",chave);
            }
            else 
            {

                printf("Item %d não removido\n",chave);
            }

        }
        else if(c=='B') //procurar o item podendo ser binário ou linear
        {
            scanf("%d",&chave);
            if(buscalista(lista,criaitem(chave))== -1)
            {
                printf("Item %d nao foi localizado na lista\n",chave);
            }
            else
            {
                printf("Item %d foi localizado na lista\n",chave);
            }
        }
        else //para mostrar a lista, no caso seria M
        {
            mostralista(lista);
        }


    }


    return 0;
}



void crialista(struct Lista *lista,int n)
{
    lista->itens= (int *)malloc(n*(sizeof(int)));
    lista->qt= 0;
    lista->tamanho=n;
}

struct Item criaitem(int n)
{
    struct Item it;
    it.chave = n;
    return it;
}

void inseriritem(struct Lista *lista, struct Item it)
{
    int achei,i,j;
    if(!listacheia(*lista)) //se ela n tiver cheia ela faz a operação de procura
    {
        achei=0;
        i=0;
        while(i<lista->qt && !achei) // achar a posicao correta para inserir o numero
        {
            if(lista->itens[i] > it.chave) 
            {
                achei=1;
            }
            else
            {
                i++;
            }           
        }
        for(j=lista->qt-1;j>=i;j--) //jogar todos para direita quando necessario
        {
            lista->itens[j+1] = lista->itens[j];
        }
        lista->itens[i]=it.chave;
        lista->qt ++;

    }

}


int listacheia(struct Lista lista)
{
    return lista.qt == lista.tamanho;
}


void mostralista(struct Lista lista)
{
    int i;
    for(i=0;i<lista.qt;i++)
    {
        printf("%d%s",lista.itens[i],i<lista.qt-1?" ":"\n");
    }
}

int buscalista(struct Lista lista,struct Item it)
{
    int i;
    int esq=0, dir=lista.qt-1, meio;
    while(esq<=dir)
    {
        meio = (esq+dir)/2;
        if(lista.itens[meio] == it.chave) return meio;
        else if (lista.itens[meio] > it.chave)
        {
            dir=meio-1;
            
        }
        else 
        {
            esq = meio+1;
        }   
    }
    return -1;

}

int removeitem(struct Lista *lista,struct Item it)
{   
    int aux2, aux = buscalista(*lista,it); 
    int i;
    if(aux!=-1)
    {
        aux2=lista->itens[aux];
        for(i=aux;i<lista->qt-1;i++)
        {
            lista->itens[i]=lista->itens[i+1];
        }
        lista->qt--;        
        return aux2;
    }
    return -1;

}