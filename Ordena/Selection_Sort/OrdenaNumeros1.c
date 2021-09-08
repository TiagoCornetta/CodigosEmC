// Selection Sort

#include <stdio.h>
#include <stdlib.h>

void ordena(int *,int);

int main()
{
    int *v;
    int n;
    int i,h;
    scanf("%d",&n);
    v=(int *)(malloc(n*sizeof(int)));

    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    } 
    ordena(v,n);

    for(h=0;h<n;h++)
    {
        if(h<n-1)printf("%d ",v[h]);
        else printf("%d\n",v[h]);
    }
    free(v);

}



void ordena(int *v,int n)
{

    int i,t;    
    for(i=0;i<n-1;i++)
    {
        int indice,aux;
        indice=i;
        for(t=1+i;t<n;t++)
        {
            if (v[t]<v[indice])
            {
                indice=t;
            }
        }
        aux=v[i];
        v[i]=v[indice];
        v[indice]=aux;
    }
}