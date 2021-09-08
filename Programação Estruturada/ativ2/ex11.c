#include <stdio.h>

void test(int);



int main()
{
    int x;
    scanf("%d",&x);
    test(x);

}

void test(int x)
{
    int contador=0;
    for(int i=1; i<=x;i++)
    {
        if (i*i == x) 
        {
            contador+=1;
            i=x+1;
        }
        if(i*i>x)
        {
            i=x+1;
        }    
    }
    if (contador==1)  printf("Eh um quadrado perfeito!\n");
    else printf("Nao eh um quadrado perfeito!\n");

}