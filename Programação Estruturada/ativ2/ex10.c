#include <stdio.h>


float temp(float);


int main()
{
    float x,h;
    scanf("%f",&x);
    h = temp(x);
    printf("%.2f\n",h);
}

float temp(float x)
{
    float c;
    c = (x - 32.0) *(5.0/9.0);
    return c;
}