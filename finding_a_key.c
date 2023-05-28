#include<stdio.h>

void read(char asentence[][100],int n);
void display(char bsentence[][100],int n);
int check(char bsentence[],char key[]);

void main()
{
    int n;
    char sentence[100][100];
    printf("Enter the number of lines\n");
    scanf("%d",&n);
    getchar();
    read(sentence,n);
    display(sentence,n);
}

void read(char asentence[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        gets(asentence[i]);
    }
}

void display(char bsentence[][100],int n)
{
    int max,max1=0,k,c,tp;
    char key[10];
    printf("Enter the key word that you want to search for\n");
    scanf("%s",key);
    for(int i=0;i<n;i++)
    {
        tp=check(bsentence[i],key);
        if(tp==1)
        {
             puts(bsentence[i]);
        }
    }
}

int check(char bsentence[],char key[])
{
    int a[10],i=0,j=1,tp=0;
    while(bsentence[i]!='\0')
    {
        tp=0;
        if(bsentence[i]==key[0])
        {
            while(key[j]!='\0')
            {
                if(bsentence[i+j]!=key[j])
                   {
                       break;
                   }
                   j++;
            }
            if(key[j]=='\0')
            {
                tp=1;
                break;
            }
            else
            {
                j=0;
            }
        }
        i++;
    }
    return tp;
}
