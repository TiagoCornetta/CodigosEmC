#include<stdio.h>
#include<stdlib.h>


void quick(int *,int,int);
int particiona(int *,int,int);

int main()
{
    int *v,i,n,h;
    scanf("%d",&n);
    v=(int *)malloc(n*(sizeof(int)));

    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }

    quick(v,0,n-1);

    for(h=0;h<n;h++)
    {
        printf("%d ",v[h]);
    }
    printf("\n");
    free(v);
    return 0;
}

void quick(int *v,int inicio,int fim)
{
    int p;
    if(inicio<fim)
    {
        p= particiona(v,inicio,fim);
        quick(v,inicio,p-1);
        quick(v,p+1,fim);
    }
}


int particiona(int *v,int inicio,int fim)
{
    int pivo = v[fim],troca=inicio-1,i,aux;

    for(i=inicio;i<fim;i++)
    {
        if (v[i]<=pivo)
        {
            troca+=1;
            aux=v[i];
            v[i]=v[troca];
            v[troca]=aux;
        }
    }
    aux= v[fim];
    v[fim]= v[troca+1];
    v[troca+1]=aux;
    return (troca+1);

}