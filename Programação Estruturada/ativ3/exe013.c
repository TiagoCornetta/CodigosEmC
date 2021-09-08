#include <stdio.h>
#include <string.h>

int main()
{
    char c[8];
    scanf("%s",c);
    int i,h;    
    h= strlen(c);
    
    while(h>5)
    {
        printf("Digite novamente a string com ate 5 caracteres:\n");
        scanf("%s",c);
        h= strlen(c);
    }

    
  
    
    
    for(i=h-1;i>=0;i--)
    {
        if (i!=0)printf("%c ",c[i]);
        else printf("%c",c[i]);
    } 
    printf("\n");
    


    return 0;
}