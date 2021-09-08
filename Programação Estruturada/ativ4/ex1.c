#include <stdio.h>


int main()
{
    int v[3][3];
    int i,j,h,k,indice_maior,coluna_maior,indice_menor,coluna_menor,maior,menor;
    for (i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }

    maior = v[0][0];
    menor = v[0][0];

     for (h=0;h<3;h++)
    {
        for(k=0;k<3;k++)
        {
            if (v[h][k]>maior)
            {
                maior=v[h][k];
                indice_maior=h;
                coluna_maior=k;
            }
            if(v[h][k]<=menor)
            {
                menor= v[h][k];
                indice_menor=h;
                coluna_menor=k;
            }
        }
    }

    printf("Maior: %d\n",maior);
    printf("Posicao (maior):%d linha e %d coluna\n",indice_maior,coluna_maior);
    printf("Menor: %d\n",menor);
    printf("Posicao (menor):%d linha e %d coluna\n",indice_menor,coluna_menor);




    return 0;
}