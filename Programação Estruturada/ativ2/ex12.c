#include <stdio.h>

float soma(float,float);
float divisao(float,float);
float sub(float,float);
float mult(float,float);


int main()
{
    float a,b,aux;
    char t;
    scanf("%f %f %c",&a,&b,&t);

    if(t=='+') aux=soma(a,b);
    if(t=='-') aux=sub(a,b);
    if(t=='*') aux=mult(a,b);
    if(t=='/') aux=divisao(a,b);
    printf("%f\n",aux);


    return 0;
}


float soma(float a,float b)
{
    return a+b;
}

float sub(float a ,float b)
{
    return a-b;
}

float mult(float a ,float b)
{
    return a*b;
}


float divisao(float a ,float b)
{
    return a/b;
}
