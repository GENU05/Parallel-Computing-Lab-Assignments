#include<stdio.h>
#include<omp.h>

int main()
{
   int t ; 
   printf("0. Serial \n 1. Parallel\n");
   scanf("%d" , &t ) ;
int k= 1;
   #pragma omp parallel if(t)
   {	
	
	if(omp_get_thread_num())
		k = omp_get_num_threads();
		
       if(omp_in_parallel())
       {
           printf("PArellel %d Thread id : %d \n" , t , omp_get_thread_num());
       }
       else
        printf("Serial %d Thread id : %d \n" , t , omp_get_thread_num());
   }
printf(" Number : %d \n" , k );
}
