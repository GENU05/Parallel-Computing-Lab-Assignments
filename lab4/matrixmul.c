#include <stdio.h>
#include <omp.h>
const int size = 3;

int main()

{

float a[size][size];
float b[size][size];
float c[size][size];
int i,j,k;
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            scanf("%f",&a[i][j]);
        }
    }
        for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            scanf("%f",&b[i][j]);
        }
    }
        for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            c[i][j]=0.0f;
        }
    }
    #pragma omp parallel for shared(a,b,c)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i=0;i<size;i++)
    {
    	for(int j=0;j<size;j++)
    		printf("%.2f ",c[i][j]);
    	printf("\n");
    }

    return 0;
}