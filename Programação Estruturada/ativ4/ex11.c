#include <stdio.h>
#include <stdio.h>


int soma(int);

int main()
{
    int n,h;
    scanf("%d",&n);
    
    if(n<0) h= soma(-n);
    else h=soma(n);
   
    printf("%d\n",h);
    return 0;
}

int soma(int n)
{
    if (n==1) return 1;
    return n+ soma(n-1);

}