#include <stdio.h>

int verificar(int *,int,int);

int main()
{
    int v[10];
    int i,aux,h,contador=0;

    for(i=0;i<10; )
    {
        scanf("%d",&aux);
        h= verificar(v,aux,contador);
        if(h==0)
            {
            v[i]=aux;
            i+=1;
            contador+=1;
            }
        else if(h==1) 
        {
            printf("Numero já digitado! Digite outro numero!\n");
        }
    }


    for(int t=0;t<10;t++)
    {
        printf("%d\n",v[t]);
    }


    return 0;
}

int verificar(int *v,int x,int contador)
{
    for(int i=0;i<contador;i++)
    {
     if (v[i]==x)return 1;   
    }
    return 0;
}