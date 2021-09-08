#include <stdio.h>
#include <stdio.h>


int imprimir(int,int);

int main()
{
    int n,h=0;
    scanf("%d",&n);
    
    imprimir(n,h);
    return 0;
}

int imprimir (int n,int h)
{
    if (n==0)
    {
        printf("%d\n",h);
        return 0;
    }


    printf("%d ",h);
    return imprimir(n-1,h+1);
    
}