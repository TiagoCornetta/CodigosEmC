// Insertion Sort

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
    int i,j,chave;

    for(i=1;i<n;i++)
    {
        chave=v[i];
        j=i-1;
        while(j>=0 &&(v[j]>v[j+1]))
        {
            v[j+1]=v[j];
            v[j]=chave;
            j-=1;
        }
    }

}