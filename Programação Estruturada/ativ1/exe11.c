#include <stdio.h>
#include <math.h>
int main()

{
    float x,y,t;
    scanf("%f",&t);
    if (t>=1 && t<=4)
      {  
        scanf("%f %f",&x,&y); 
        float z;
        z=x/y; 
        if (t==1)
        {
            printf("O resultado da soma eh: %.0f\n", x+y);
        }
        else if (t==2)
        {
            printf("O resultado da subtracao eh: %.0f\n", x-y);
        }
        else if (t==3)
        {
            printf("O resultado da divisao eh: %f\n", z);
        }
        else if (t==4)
        {
            printf("O resultado da multiplicacao eh: %.0f\n", x*y);
        }
      }    
    else 
        {
         printf("Numero Invalido!\n");
        }
    return 0;
}