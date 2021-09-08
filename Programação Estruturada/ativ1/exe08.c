#include <stdio.h>
#include<math.h>

int main()

{   
    float x,y,r;
    scanf("%f %f",&x,&y);
    r =  sqrt( (x*x) + (y*y));    

    printf("A hipotenusa eh: %f\n",r);


    return 0;
}