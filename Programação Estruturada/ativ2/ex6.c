#include <stdio.h>

#include <stdio.h>

float soma(int);

int main()
{

    int x;
    scanf("%d",&x);
    printf("%.1f\n",soma(x));
    return 0;
}

float soma(int x)
{
    float s=0;
    for(int i=1;i<=x;i++)
    {
        
            s+= (float) 1/i;
        
    }

    return s;
}