#include <stdio.h>

int main()
{
    int v[4][4];
    int i,j,principal=0,secundaria=0,linha=0,coluna=3,total=0;
    for (i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }

     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==j) principal += v[i][j];
            total+= v[i][j];
        }
    }

     for(i=0;i<4;i++)
    {
        secundaria += v[linha][coluna];
        linha+=1;
        coluna-=1;
    }

   printf("Soma: %d\n",total-principal-secundaria);
    
    return 0;
}