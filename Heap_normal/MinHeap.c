#include <stdio.h>
#include <stdlib.h>



void final(int *,int);
int filho_esq(int);
int filho_di(int);
int ultimo_pai(int);
void peneirar(int *,int,int);



int main()
{
    int n,i,*v;
    scanf("%d",&n);

    while(n!=0)
    {
        v= (int*)malloc(n*(sizeof(int))); //cria a estrutura do vetor
        for(i=0;i<n;i++)
        {
            scanf("%d",&v[i]);//implementa os dados no vetor
        }
        
        final(v,n); //arruma o vetor
        for(i=0;i<n;i++) //imprime os dados no vetor
        {
            if(i<n-1)printf("%d ",v[i]) ;
            else printf("%d\n",v[i]);
        }
        free(v);
        scanf("%d",&n);
    }
    return 0;
}


int filho_esq(int n) //encontrar o filho da esquerda
{
    int aux;
    aux= (2*n)+1;
    return aux;
}

int filho_di(int n) //encontrar o filho da direita
{
    int aux;
    aux= (2*n)+2;
    return aux;
}

int ultimo_pai(int n)//encontrar o ultimo pai 
{
    int aux;
    aux=(n/2)-1;
    return aux;
}


void final(int *v,int qt) //percorrer todos os pais e chamar a função para arrumar o vetor 
{
    int i;
    for(i=ultimo_pai(qt);i>=0;i--)
    {
        peneirar(v,i,qt);
    }
}



void peneirar(int *v,int i,int qt) //arrumar o vetor e chamar sempre que possivel recursivamente para verificar
{
    int aux=i,aux1; 
     if(filho_di(i)<qt && v[filho_di(i)] < v[aux]) // conferir se o filho da direita é menor
    {
        aux= filho_di(i);
    }
    
    if( filho_esq(i)<qt && v[filho_esq(i)]< v[aux])  //conferir se o filho da esquerda é menor
    {
        aux= filho_esq(i);  
    }
    if(aux != i)
    {
        aux1= v[i];
        v[i]= v[aux];
        v[aux]=aux1;     
        peneirar(v,aux,qt); //agora chamar de novo para conferir a parte da arvore alterada
    }

}