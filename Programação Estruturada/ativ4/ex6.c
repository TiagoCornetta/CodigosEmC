#include <stdio.h>

int main()

{
    int v[3][3];
    int i,k,p=0,s=0,t=0;
    for(i=0;i<3;i++)
    {
        for(k=0;k<3;k++)
        {
            scanf("%d",&v[i][k]);
        }
    }

    for(i=0;i<3;i++)
    {
        for(k=0;k<3;k++)
        {
            if(i<k) p+=v[i][k]; 
        }
    }
    printf("%d\n",p);

    return 0;
}