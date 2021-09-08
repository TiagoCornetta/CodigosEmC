#include <stdio.h>

int main()
{
    float v[5];
    int i,z,qt;
    float soma;



    for (i=0;i<5;i++)
    {
        scanf("%f",&v[i]);
    }



    for(z=0;z<5;z++)
    {
     if (v[z]>0)soma = soma +v[z];
     if(v[z]<0)qt+=1;
    }

    printf("%d\n",qt);
    printf("%f\n",soma);

    return 0;
}