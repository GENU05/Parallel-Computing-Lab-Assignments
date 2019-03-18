#include <stdio.h>
#include <omp.h>
#include<stdio.h>
#include<omp.h>

const int n = 3;

int main()

{
int i,j,sumR,sumC;
float a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f",&a[i][j]);
        }
    }
    #pragma omp parallel for shared(a)
    
    for (i = 0; i < n; i++)
    {
        sumR = 0;
        for (j = 0; j < n; j++)
        {
            sumR += a[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, sumR);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        sumC = 0;
        for (j = 0; j < n; j++)
        {
            sumC += a[j][i];
        }
        printf("Sum of column %d = %d\n", i + 1, sumC);
    }
    return 0;
}