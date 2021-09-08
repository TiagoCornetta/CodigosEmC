#include <stdio.h>


void ordena(float *);

int main()
{
    float v[10];
    int i;


    for (i=0;i<10;i++)
    {
        scanf("%f",&v[i]);
    }

    ordena(v);



    return 0;
}



void ordena(float *v)
{
int i,j,indice;
float aux;

for(i=0;i<9;i++)
{
    indice=i;
    for(j=i+1;j<10;j++)
    {
        if(v[j]<v[indice])
        {
            indice=j;
        }
    }
    aux= v[i];
    v[i]= v[indice];
    v[indice]=aux;
}


for(int h=0;h<10;h++)
{
    printf("%.1f\n",v[h]);

}


}