#include <stdio.h>
#include <string.h>

int main()
{
    char c[8];
    scanf("%s",c);
    int i,h;
    h= strlen(c);
    
    while(h!=8)
    {
        printf("Voce digitou uma string com %d caractere(s)!\n",h);
        printf("A string deve ter 8 caracteres. Por favor, digite uma nova string:\n");
        scanf("%s",c);
        h= strlen(c);
    }



    for(i=0;i<4;i++)
    {
        printf("%c",c[i]);
    }
    printf("\n");

    return 0;
}