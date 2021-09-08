#include <stdio.h>

int main()

{
    float r1b,r1a,r2b,r2a;
    scanf("%f %f %f %f",&r1b,&r1a,&r2b,&r2a);
    
    if (r1b == r1a || r2b==r2a)
    {
        printf("Os dados informados nao formam o retangulo A ou o retangulo B!\n");
    }
    else 
    {
        {
            printf("A area do retangulo A eh: %f\n",r1b*r1a);
            printf("A area do retangulo B eh: %f\n",r2a*r2b);
        }
        if (r2a*r2b > r1b*r1a)
        {
            printf("A area do retangulo B eh maior do que a do retangulo A!\n");
        }
        else if(r2a*r2b < r1b*r1a)
        {
            printf("A area do retangulo A eh maior do que a do retangulo B!\n");
        }
        else 
        {
            printf("A area do retangulo A eh igual ao do retangulo B!\n");
        }
    }
    return 0;
}