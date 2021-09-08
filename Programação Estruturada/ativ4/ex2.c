#include <stdio.h>


int main()
{
    int n;
    scanf("%d",&n);
    int v[n][n];
    int i,h;

    for(i=0;i<n;i++)
    {
        for(h=0;h<n;h++)
        {
            if(h==i) v[i][h]=1;
            else v[i][h]=0;
        }
    }

    for(int t=0;t<n;t++)
    {
        for(int j =0;j<n;j++)
        {
            if(j<n-1) printf("%d ",v[t][j]);
            else printf("%d\n",v[t][j]);
        }
    }


    return 0;
}