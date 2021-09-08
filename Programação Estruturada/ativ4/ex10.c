#include<stdio.h>


int cubo(int);


int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",cubo(n));

    return 0;
}


int cubo(int n)
{
    if (n==1) return 1;
    else
    {
        return (n*n*n) + cubo(n-1);
    }

}