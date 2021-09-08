#include <stdio.h>

float soma(int);
int fatorial(int);
int main()
{

    int x;
    scanf("%d",&x);
    printf("%f\n",soma(x));
    return 0;
}

float soma(int x)
{
    float s=0;
    float aux;
    for(int i=1;i<=x;i++)
    {
        aux= fatorial(i);
        
        s+= (float) (1/aux);       
    }
    return s;
}



int fatorial(int y)
{
    int h=1;
    for(int i=1;i<=y;i++)
    {
        h= h*i;
    }
    return h;
}