#include <stdio.h>

int main()
{
    char c[8];
    scanf("%s",c);
    int i,contador=0;

    for(i=0;c[i]!='\0';i++)
    {
        printf("%c\n",c[i]);
        contador+=1;
    } 

    printf("%d\n",contador);
    


    return 0;
}