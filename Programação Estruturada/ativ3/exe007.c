#include <stdio.h>

int main()
{
    int a[5];
    int b[5];
    int c[5];
    int i,t,z,h;

    for(i=0;i<5;i++)
    {
       scanf("%d",&a[i]); 
    }

    for(t=0;t<5;t++)
    {
        scanf("%d",&b[t]); 

    }

    for(z=0;z<5;z++)
    {
        c[z] = a[z]-b[z];
    }
    
    
    for(h=0;h<5;h++)
    {
        if (h!=4)printf("%d ",c[h]);
        
        else printf("%d\n",c[h]);
            
    }






    return 0;
}

