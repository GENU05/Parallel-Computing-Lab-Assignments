#include<stdio.h>
#include<omp.h>

int main()
{
    int n , t ; 
    #pragma omp parallel private(t)
    {
        t = omp_get_thread_num() ; 
        printf("Thread number : %d\n" , t ) ; 
        if(t==0)
        {
            n = omp_get_num_threads() ;
        }
    }
	printf("Total Threads %d \n" , n ) ; 
	return 0 ;
}
