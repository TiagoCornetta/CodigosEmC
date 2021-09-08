#include <stdio.h>

int verificar(int *,int,int);

int main()
{
  int v[10];
  int par[10];   //vetor que vao os n pares
  int impar[10]; //vetor que vao os n impar
  int i,z,t,g,aux1=0,aux2=0,maior,menor;
  
  for(i=0;i<10;i++)
  {
    scanf("%d",&v[i]);
  }
  

  maior=v[0];
  menor=v[0];


  for(i=0;i<10;i++)
  {
      if(v[i]%2==0)
      {
         int h= verificar(par,v[i],aux1);
         
         if (h == 0)
         { 
            par[aux1]=v[i];
             if (i<9) aux1+=1;
         }
      }
      else
      {
          if((verificar(impar,v[i],aux2))==0)
          {
            impar[aux2]=v[i];
            if (i<=9) aux2+=1;
          }
      }
      if(v[i]>maior)maior=v[i];
      if(v[i]<menor)menor=v[i];
  }

  printf("Numeros pares:\n");
  for(g=0;g<aux1;g++)
  {
      printf("%d\n",par[g]);
  }
  
  printf("Numeros impares:\n");
  for(t=0;t<aux2;t++)
  {
   printf("%d\n",impar[t]);   
  }

  printf("Maior:%d\n",maior);
  printf("Menor:%d\n",menor);    
  return 0;
}



int verificar(int *vetor,int x,int n)
{
    for(int i=0; i<n;i++)
    {
        if(vetor[i]==x)
        {
            return 1;
        }
    }
    return 0;
}