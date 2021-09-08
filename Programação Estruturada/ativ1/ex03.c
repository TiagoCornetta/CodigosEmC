#include <stdio.h>

int main()

{
    int y,x;
    scanf("%d",&y);
    scanf("%d",&x);
    if (y==x)
    {
        printf("Mesma quantidade!\n");
    }
    else if (y>x)
    {
        printf("Quantidade de alunas eh maior do que de alunos!\n");
    }
    else 
    {
        printf("Quantidade de alunos eh maior do que de alunas!\n");
    }




    return 0;
}