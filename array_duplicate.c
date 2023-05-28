#include<stdio.h>


int main()
{
    int a[25],count=0,k,m=0,l;
    for(int i=0;i<25;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<25;i++)
    {
        count=0;
            for(int j=i+1;j<25;j++)
        {
                if(a[i]==a[j] && a[i]!=0)
               {
                a[j]=0;
               count++;
              }
        }
        if(count>0)
        {
            printf("The element %d was reapeated %d times\n",a[i],count);
        }
    }
}
