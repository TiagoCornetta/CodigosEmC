#include<stdio.h>


int verificar(int *,int,int);

int main()
{
    int v[6];
    int i,z,aux1,aux2,somador=0;
    int r[6];

    for(i=0;i<6;i++)
    {
        scanf("%d",&v[i]);
    }

    aux2=0;
    
    for(z=0;z<6;z++)
    {
       for(int t=z+1; t<6;t++)
       {
           if (v[z]==v[t])
           {
               if(verificar(r,v[z],aux2) == 1)
               {
                   r[aux2]= v[z];
                   aux2+=1;
               }
           }

       }

    }

    if(aux2==0) printf("Nao existem valores iguais!\n");
    
    else
    {
        for(int t=0;t<aux2;t++)
        {
            printf("%d\n",r[t]);
        }
    }


    return 0;
}






int verificar(int *vetor,int x,int n)
{
    for(int i=0; i<n;i++)
    {
        if(vetor[i]==x)
        {
            return 0;
        }
    }
    return 1;
}