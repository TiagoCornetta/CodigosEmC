#include <stdio.h>


void dia(int);

int main()
{
    int x=0;
    while(x<1 || x>7)
    {
        scanf("%d",&x);
        dia(x)  ; 
    }

    return 0;
}

void dia(int x)
{
    if(x<1 || x>7) printf("O numero deve ser >=1 e <=7!\n");
    else 
    {
        if(x==2) printf("Segunda-feira\n");
        if(x==3) printf("Terça-feira\n");
        if(x==1) printf("Domingo\n");
        if(x==4) printf("Quarta-feira\n");
        if(x==5) printf("Quinta-feira\n");
        if(x==6) printf("Sexta-feira\n");
        if(x==7) printf("Sabado\n");
    }

}

