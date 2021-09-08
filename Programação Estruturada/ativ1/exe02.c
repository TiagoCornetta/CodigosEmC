#include <stdio.h>


int main()

{   
    int x,y,z;
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);

    printf("%d notebook(s) da Sony\n",x);
    printf("%d notebooks(s) da Dell\n",y);
    printf("%d notebook(s) da Toshiba\n",z);
    printf("Total de %d notebooks\n",x+y+z);


    return 0;
}