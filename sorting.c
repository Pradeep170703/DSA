#include<stdio.h>
#include<string.h>
#include<time.h>
#define size 10000

void bubblesort(int a[size],int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
  for(j=01;j<n-i-1;j++)
  {

   if(a[j]>a[j+1])
   {
     temp=a[j];
     a[j]=a[j+1];
     a[j+1]=temp;
   }
  }
  }
  printf("After sorting by bubble sort\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}
void selectionsort(int a[size], int n)
{
    int indexofmin, temp, j;
    for (int i = 0; i < n - 1; i++)
    {
        indexofmin = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexofmin])
            {
                indexofmin = j;
            }
        }
        temp = a[i];
        a[i] = a[indexofmin];
        a[indexofmin] = temp;
    }
     printf("After sorting by selection sort\n");
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}

void insertionsort(int a[size],int n)
{
    int key,i,j;
    for(i=1;i<n;i++)
    {
       j=i-1;
       key=a[i];
       while(j>=0 && a[j]>key )
       {
           a[j+1]=a[j];
           j--;
       }
       a[j+1]=key;
    }
     printf("After sorting by insertion sort\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    int n,rnum;
    FILE *fp,*fp1,*fp3;
    float duration[4];
    int a[size],x;
    clock_t start,end;
    int first,last;
    printf("Enter the interval\n");
    scanf("%d%d",&first,&last);
    printf("Enter number of random numbers to be generated\n ");
    scanf("%d",&n);
    fp=fopen("input.txt","w");
    fp1=fopen("output.txt","w");
    fp3=fopen("log.txt","w");
    //read_array(a,n);
    for(int i=0;i<n;i++)
    {

        a[i]=(rand()%(last+1-first)+first);
        fprintf(fp,"%d ",a[i]);

    }
    start=clock();
    bubblesort(a,n);
    for(int i=0;i<n;i++)
    {
        fprintf(fp1,"%d ",a[i]);

    }
    end=clock();
    duration[0]=(float)(end-start);
    printf("\n Duration is for bubble sort %f\n",duration[0]);
    start=clock();
    selectionsort(a,n);
     end=clock();
     duration[1]=(float)(end-start);
     printf("\n Duration is for selection sort %f\n",duration[1]);
     start=clock();
     insertionsort(a,n);
     end=clock();
     duration[2]=(float)(end-start);
     printf("\n Duration is for insertion sort %f\n",duration[2]);
     fprintf(fp3,"\n Duration is  bubble sort %f\n",duration[0]);
      fprintf(fp3,"\n Duration is  selection sort is  %f\n",duration[1]);
       fprintf(fp3,"\n Duration is  insertion sort is %f\n",duration[2]);
    return 0;
}
