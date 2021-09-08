#include <stdio.h>

int soma(int);

int main()
{

    int x;
    scanf("%d",&x);
    printf("%d\n",soma(x));
    return 0;
}

int soma(int x)
{
    int s=0;
    for(int i=1;i<x;i++)
    {
        if (x%i==0)
        {
            s+=i;
        }
    }

    return s;
}