#include<stdio.h>

void read(int m, int n, int *matrix);
void multiplication(int m, int n, int a, int b, int *matrix1, int *matrix2, int *result);
void print(int m, int b, int *result);

int main()
{
    int i, j, m, n, a, b;
    printf("Enter the number of rows and columns in first matrix\n");
    scanf("%d%d",&m,&n);
    printf("Enter the number of rows and columns in second matrix\n");
    scanf("%d%d",&a,&b);

    if(n == a)
    {
        int matrix1[m][n], matrix2[a][b], result[m][b];
        read(m, n, &matrix1[0][0]);
        read(a, b, &matrix2[0][0]);
        multiplication(m, n, a, b, &matrix1[0][0], &matrix2[0][0], &result[0][0]);
        print(m, b, &result[0][0]);
    }
    else
    {
        printf("The given matrices cannot be multiplied.\n");
    }
    return 0;
}

void read(int m, int n, int *matrix)
{
    printf("Enter the elements of the matrix\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", (matrix + i*n + j));
        }
    }
}

void multiplication(int m, int n, int a, int b, int *matrix1, int *matrix2, int *result)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < b; j++)
        {
            *(result + i*b + j) = 0;
            for(int k = 0; k < n; k++)
            {
                *(result + i*b + j) += *(matrix1 + i*n + k) * *(matrix2 + k*b + j);
            }
        }
    }
}

void print(int m, int b, int *result)
{
    printf("The multiplied matrix is \n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < b; j++)
        {
            printf("%d ", *(result + i*b + j));
        }
        printf("\n");
    }
}
