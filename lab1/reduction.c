#include<stdio.h>
#include<omp.h>

int main()
{
   int x = 0 ; 
   #pragma omp parallel reduction(+:x)
   {
       int tid = omp_get_thread_num();
       x = x + 1 ; 
       printf("Threads [%d] :: x = %d\n" , tid , x );
   }
}
