#include <stdio.h>
#include <stdlib.h>


void merge(int *,int,int);
void intercala(int *,int,int,int);


int main()
{
    int *v,n,i,k;
    scanf("%d",&n);
    v= (int *)malloc((n+2)*(sizeof(int)));

    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }

    merge(v,0,n-1);

    for(k=0;k<n;k++)
    {
        if (k<n-1) printf("%d ",v[k]);
        else printf("%d\n",v[k]);
    }
    free(v);
    return 0;
}


//chamada recursiva
void merge(int *v,int inicio,int final)
{
    int meio;
    if(inicio<final)
    {
        meio= ((final+inicio)/2);
        merge(v,inicio,meio);
        merge(v,meio+1,final);
        intercala(v,inicio,meio+1,final);
    }
}







void intercala(int *v,int inicio,int meio,int final)
{
    //vetor auxiliar que irei utilizar
    int tamanho= final- inicio+1;
    int *aux;
    aux= (int *)(malloc( (tamanho)*(sizeof(int))));
    // para passagem do vetor

    int lim_esq= meio-1;
    int i,j,x; // i(vetor esquerdo) j(vetor direito) x(para o vetor auxiliar)
    int k,l; //parametros para passar para o vetor original

    //comparacao entre os dois vetores
    for (i=inicio,j=meio,x=0;i<=lim_esq && j<=final; x++)
    {
        if(v[i]<v[j])
        {
            aux[x]=v[i];
            i++;
        }
        else
        {
            aux[x]=v[j];
            j++;
        }
    }
    //pegar o que sobra
    for(;i<=lim_esq;i++,x++) //resto do esquerdo
    {
        aux[x]=v[i];
    }

    for(;j<=final;j++,x++) //resto do direito
    {
        aux[x]=v[j];
    }

    //passar para o vetor original
    for(k=inicio,l=0;k<=final;k++,l++)
    {
        v[k]=aux[l];
    }

    free(aux); //liberar o vetor


}