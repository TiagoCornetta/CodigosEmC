#include <stdio.h>


int main()
{
    int x;
    scanf("%d",&x);
    int aux=1,aux2=1;
    for(int i=1;i<=x;i++)
      {  for(int t=1;t<=aux;t++)
            {
                if (t<aux)
                    {
                        printf("%d ",aux2);
                        aux2+=1;
                    }   
                else
                 {
                        printf("%d\n",aux2);
                        aux2+=1;
                 }
            }
            aux+=1;
      }
    return 0;
}