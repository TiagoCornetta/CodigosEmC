#include <stdio.h>

int main()
{
    int n, menor,aux2=0;
    scanf("%d",&n);
    if (n==0) printf("Nenhum calculo foi realizado!\n"); 
    while(n!=0)
    {        
        int aux=0;
        if (n==1)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                aux= a +b;
                printf("(a+b) = %d\n",aux);
            }
        if (n==2)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                aux= a +b +c;   
                printf("(a+b+c) = %d\n",aux);
            }
        if (n==3)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                aux= a *b;
                printf("(a*b) = %d\n",aux);
                
            }
        
        if (aux<menor || aux2==0)
            {
                menor=aux;
            }
        aux2+=1;
        scanf("%d",&n);  
    }
    
    if(aux2!=0)printf("Menor resultado: %d\n",menor);

}
