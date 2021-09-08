#include<stdio.h>

int somatorio (int *,int);

int main()
{
    int v[4],h=0;

    for (int i = 0; i < 4; i++)
    {
        scanf("%d",&v[i]);
    }
    
    h=somatorio(v,h);

    printf("%d\n",h);
    return 0;
}

int somatorio(int *v,int h)
{
    if (h==3) return v[h]; 
    return v[h] + somatorio(v,h+1);
}