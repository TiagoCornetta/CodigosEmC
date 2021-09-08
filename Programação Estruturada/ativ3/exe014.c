#include <stdio.h>
#include <string.h>



int main()
{
    char c[8];
    char t;
    scanf("%s %c",c,&t);
    
   
    int i,h,contador=0;   

    char vogais[5]={'a','e','i','o','u'};
    
    
    
    for(i=0;i<8;i++)
    {
        for(h=0;h<5;h++)
        {
            if(c[i]==vogais[h])
            {
                contador+=1;
                c[i]=t;
            }
        }
    }

    
  


    printf("A string possui %d vogais.\n",contador);
    printf("%s\n",c);
     
    


    return 0;
}