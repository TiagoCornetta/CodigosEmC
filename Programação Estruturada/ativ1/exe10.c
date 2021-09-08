#include <stdio.h>

int main()

{   
    int x;scanf("%d",&x);
    
    
    if (x>7 || x<1)
    {
        printf("Numero Invalido!\n");
    }    
    else
    {   
        if (x==1)
        {
            printf("Domingo!");
        }
        if (x==2)
        {
            printf("Segunda-feira!");
        }
        if (x==3)
        {
            printf("Terca-feira!");
        }
          if (x==4)
        {
            printf("Quarta-feira!");
        }
          if (x==5)
        {
            printf("Quinta-feira!");
        }
          if (x==6)
        {
            printf("Sexta-feira!");
        }
          if (x==7)
        {
            printf("Sabado!");
        }
    } 
    return 0;
}