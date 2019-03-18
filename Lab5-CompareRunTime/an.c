#include <stdio.h>
#include <sys/time.h>
#include <omp.h>
#include <stdlib.h>
#include<time.h>
int main(void){
    clock_t start, end;
     double cpu_time_used;
     
     start = clock(); 

    double pi,x;
int i,N;
pi=0.0;
N=1000;
    #pragma omp parallel for private(x) reduction(+:pi)
    for(i=0;i<=N;i++){
    x=(double)i/N;
    pi+=4/(1+x*x);
    }
pi=pi/N;
end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("CPU Time : %lf",cpu_time_used);
     printf("\nPi : %lf\n",pi);
}