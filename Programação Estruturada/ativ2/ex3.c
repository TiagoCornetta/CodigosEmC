#include <stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    
    while(x<0)
    {
        printf("O numero deve ser >=0!\n");
        scanf("%d",&x);
    }

    for(int i=x;i>=0;i--)
    {
        if (i>0) printf("%d ", i);
        else printf("%d\n", i);
    }
    printf("FIM!");
    return 0;
}