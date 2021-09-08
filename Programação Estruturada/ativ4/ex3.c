#include <stdio.h>

int main()
{
    int v[4][4];
    int i,j,h,k,maiores=0,menores=0;
    for (i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }

    for (h=0;h<4;h++)
    {
        for(k=0;k<4;k++)
        {
            if(v[h][k]>10)maiores+=1;
            if(v[h][k]<10)menores+=1;
        }
    }

    printf("Qtd. > 10:%d\n",maiores);

    printf("Qtd. < 0:%d\n",menores);
    return 0;
}