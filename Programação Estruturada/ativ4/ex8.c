#include <stdio.h>

int main()

{
    int v[4][4];
    int i,k,p=0,s=0,t=0;
    for(i=0;i<4;i++)
    {
        for(k=0;k<4;k++)
        {
            scanf("%d",&v[i][k]);
        }
    }

    for(i=0;i<4;i++)
    {
        for(k=0;k<4;k++)
        {
            if(i>k) p+=v[i][k]; 
        }
    }
    printf("Soma: %d\n",p);

    return 0;
}