#include <stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    int v[x+1];
    
    int h = (x/2)+1;
    int par[h];
    int impar [x/2];
    
    for(int i=0;i<x+1;i++)
    {
        v[i]= i;
    }
 
    int aux=0,aux1=0;
    for(int i=0;i<x+1;i++)
        {            
            if (i%2==0)
            {
                par[aux]= v[i];
                aux+=1;
            }
            else
            {
                impar[aux1]=v[i];
                aux1+=1;
            }
        }
    
    for(int i=0;i<x/2;i++)
    {
        if (i<(x/2)-1) printf("%d ", impar[i]);
        else printf("%d\n", impar[i]);
    }
    for(int i=0;i<h;i++)
    {
        if (i<h-1) printf("%d ", par[i]);
        else printf("%d\n", par[i]);
    }

    return 0;
}