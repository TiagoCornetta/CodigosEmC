#include <stdio.h>

int main()
{
    int v[3][3];
    int i,j,principal=0,secundaria=0,linha=0,coluna=2;
    for (i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }

     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i==j) principal += v[i][j];
        }
    }

     for(i=0;i<3;i++)
    {
        secundaria += v[linha][coluna];
        linha+=1;
        coluna-=1;
    }

    printf("Soma diagonal principal: %d\n",principal);
    printf("Soma diagonal secundaria: %d\n",secundaria);
    
    return 0;
}