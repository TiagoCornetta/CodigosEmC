#include<stdio.h>

int mult(int ,int);

int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n",mult(x,y));
    return 0;
}

int mult(int x,int y)
{
    if(y==0) return 0;
    return x +mult(x,y-1);

}