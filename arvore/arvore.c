#include <stdio.h>
#include <stdlib.h>

struct  No
{
    int chave;
    struct No *e; //filho esquerda 
    struct No *d; //filho direita
    struct No *p;// pai
};


struct Arvore
{
    struct No *raiz;//inicio da minha arvore 
};


//comandos de criacao
struct Arvore *CriaArvore();
struct No *criano(int );

//comando de inserir
void inserir(struct Arvore *,struct No *);

//comandos de impressao
void preOrdem(struct No* );
void inOrdem(struct No *);
void posOrdem(struct No *);

//comando para remover
struct No *remover(struct Arvore *,int );
struct No *sucessor(struct No *);



int main()
{
    int chave;
    struct Arvore *arvore=CriaArvore();
    struct No *aux;
    char c;


    while(scanf("\n%c",&c)!= EOF)
    {   
        if(c=='I')
        {
            scanf("%d",&chave);
            inserir(arvore,criano(chave));
        }
        else if (c=='R')
        {
            scanf("%d",&chave);
            aux= remover(arvore,chave);
            if(aux!=NULL)
            {
                printf("Item %d removido\n",aux->chave);
                free(aux);
            }

        }
        else //M 
        {
            scanf("\n%c",&c);
            if(c == 'P')//pre-ordem
            {
                preOrdem(arvore->raiz);
            }
            else if(c == 'I') //in-order 
            {
                inOrdem(arvore->raiz);
            } 
            else  //pos-ordem
            {
                posOrdem(arvore->raiz);
            }

        }
        
        


    }

    return 0;
}



struct Arvore *CriaArvore()
{
    struct Arvore *arvore;
    arvore=(struct Arvore *)malloc(sizeof(struct Arvore));
    if(arvore!= NULL)
    {
        arvore->raiz=NULL;
    }
    return arvore;
}

struct No *criano(int n)
{
    struct No *no= (struct No *)malloc(sizeof(struct No));

    if(no!= NULL)
    {
        no->chave=n;
        no->d=NULL;
        no->e=NULL;
        no->p=NULL;
    }
    return no;
}



void inserir(struct Arvore *arvore, struct No *no)
{

    struct No *pai= NULL;
    struct No *filho= arvore->raiz;

    while(filho != NULL)
    {
        pai=filho;
        if(no->chave > filho->chave) //ele vai para direita
        {
            filho=filho->d; //indo para direita
        }
        else 
        {
            filho=filho->e; //vai para esquerda
        }
    }

    if(pai!= NULL) //inserindo na folha
    {
        no->p=pai;
        if(pai->chave > no->chave) //inserindo na esquerda
        {
            pai->e=no;
        }
        else //inserindo na direita pois é maior
        {
            pai->d=no;
        }
    }
    else // ele vai inserir na raiz
    {
        arvore->raiz=no; //inserindo o novo item na raiz
    }
}



// Maneira de imprimir 

void preOrdem(struct No *raiz )
{
    if(raiz!= NULL)
    {
        printf("%d\n",raiz->chave);
        preOrdem(raiz->e);
        preOrdem(raiz->d);
    }
}

void inOrdem(struct No *raiz)
{
    if(raiz!=NULL)
    {
        inOrdem(raiz->e);
        printf("%d\n",raiz->chave);
        inOrdem(raiz->d);
    }
}

void posOrdem(struct No *raiz)
{
    if(raiz != NULL)
    {
        posOrdem(raiz->e);
        posOrdem(raiz->d);
        printf("%d\n",raiz->chave);
    }
}


struct No *remover(struct Arvore *arvore,int n)
{

    struct No *ant= NULL, *filho= arvore->raiz, *aux;

    // Percorrer a arvore para achar o valor desejado
    while(filho!=NULL && filho->chave!= n)
    {
        ant=filho;
        if(filho->chave<n)
        {
            filho=filho->d;
        }
        else
        {
            filho=filho->e;
        }
    }

    if(filho!=NULL)
    {
        if(filho->e==NULL && filho->d==NULL)// 1 caso folha
        {
            if(ant!=NULL) //removendo de um pai
            {    
                // Serve para limpar o endereço do pai em relacao ao filho removido
                if(ant->e==filho) //definir se ele é filho da esquerda
                {
                    ant->e=NULL;
                }
                else // ou da direita
                {
                    ant->d=NULL;
                }
            }
            else //removendo da raiz
            {
                arvore->raiz=NULL;
            }
        }
        // Pai de dois filhos
        else if(filho->e != NULL && filho->d != NULL)
        {
            aux= sucessor(filho->d);

            if(ant!=NULL) //mexendo em um lugar fora da raiz
            {
                if(ant->e == filho)
                {
                    ant->e=aux;
                }
                else 
                {
                    ant->d=aux;
                }
            }
            else //mexendo na raiz
            {
                arvore->raiz=aux;
            }
            aux->p= ant;
            aux->e=filho->e;
            if(filho->e!=NULL)
            {
                filho->e->p=aux;
            }
            aux->d= filho->d;
            if(filho->d!=NULL)
            {
                filho->d->p= aux;
            }
        }

        else 
        {
            if(ant!=NULL) //removendo de um pai
            {
                if(ant->e == filho) // o problema pode acontecer caso possua neto
                {
                    if(filho->e != NULL) //adotando o neto
                    {
                        ant->e=filho->e;
                    }
                    else 
                    {   
                        ant->e=filho->d; // n da problema pois se for igual a nulo ele limpa de qualquer jeito
                    }               
                }
                else //agora indo para direita tendo filho unico nela
                {
                    if(filho->e!=NULL)
                    {
                        ant->d=filho->e;
                    }  
                    else
                    {
                        ant->d=filho->d;
                    }
                    
                }
            }
            else //to removendo da raiz quando ant = NULL
            {
                if(filho->e != NULL)
                {
                    arvore->raiz = filho->e;
                }
                else 
                {
                    arvore->raiz= filho->d;
                }
                arvore->raiz->p=NULL;
            }

        }
    }


    return filho;
}



struct No * sucessor(struct No *filho)
{
    struct No *ant= NULL;

    while(filho!= NULL) //percorro o max a esquerda possivel
    {
        ant= filho;
        filho = filho->e;
    }
    if(ant->p->e== ant)
    {
        ant->p->e = ant->d;
        if(ant->d!= NULL)
        {
            ant->d->p = ant->p;
        }
    }
    else 
    {
        ant->p->d= ant->d;
        if(ant->d!= NULL)
        {
            ant->d->p= ant->p;
        }
    }
    return ant;
}