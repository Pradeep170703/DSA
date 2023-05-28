#include<stdio.h>
int main()
{
    int n,status=0,a[100][100],m;
    printf("Enter the row and columns of matrix\n");
    scanf("%d%d",&n,&m);
    if(n==m)
    {
        for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
     }
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(a[i][j]!=a[j][i])
             {
                 status=1;
                 break;
             }
         }
         if(status==1)
         {
             break;
         }
     }
     if(status==0)
     {
         printf("THe matrix are squared\n");
     }
    }
    else
    {
        printf("The matrix arent squared\n");
    }
}
