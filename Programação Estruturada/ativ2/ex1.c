#include <stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    int v[x+1];

    for(int i=0;i<x+1;i++)
    {
        v[i]= i;
    }

    for(int i=0;i<x+1;i++)
    {
        if (i<x) printf("%d ", v[i]);
        if(i==x) printf("%d\n", v[i]);
    }

    for(int i=x;i>=0;i--)
    {
        if (i>0) printf("%d ", v[i]);
        if(i==0) printf("%d\n", v[i]);
    }


    return 0;
}