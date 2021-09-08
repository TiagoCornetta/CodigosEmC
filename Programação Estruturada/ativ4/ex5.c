#include <stdio.h>

int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    int v[n][x];
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<x;j++)
        {

        if(i<j) v[i][j]= (2*i) +(7*j)-2; 
        if (i==j) v[i][j] = (3*i*i) -1;
        if (i>j) v[i][j] = (4*i*i*i) +(5*j*j) +1;                   
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j =0;j<x;j++)
        {
            if(j<x-1) printf("%d ",v[i][j]);
            else printf("%d\n",v[i][j]);
        }
    }

    return 0;
}