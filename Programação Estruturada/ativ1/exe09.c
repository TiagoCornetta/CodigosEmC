#include <stdio.h>


int main()

{   
    int x,y;
    scanf("%d %d",&x,&y);
    if (x>y)
    {
        printf("O %d eh o maior numero!\n",x);
    }    
    else if(y>x)
    {
        printf("O %d eh o maior numero!\n",y);
    }
    else 
    {
        printf("Numeros Iguais!\n");
    }
    

    return 0;
}