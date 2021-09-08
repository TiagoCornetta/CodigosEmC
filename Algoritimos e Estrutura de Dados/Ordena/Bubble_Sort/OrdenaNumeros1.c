//BUBBLE SORT

#include <stdio.h>
#include <stdlib.h>

void ordena(int *,int);

int main()
{
    int *v;
    int n,i;
    scanf("%d",&n);
    v= (int *) (malloc(n* sizeof(int)));
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    
    ordena(v,n);
    free(v); 

}

void ordena(int *v,int n)
{
    int i,t,h;
    int aux;
    for(i=0;i<n-1;i++)
    {
        for(t=0;t<n-1-i;t++)
        {
            if(v[t]>v[t+1])
            {
                aux=v[t];
                v[t]=v[t+1];
                v[t+1]=aux;
            }
        }
    }

    for(h=0;h<n;h++)
    {
        if(h<n-1)printf("%d ",v[h]);
        else printf("%d\n",v[h]);

    }

}