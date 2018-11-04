#include<stdio.h>
#include<omp.h>

int main()
{
  int x = 0 , i , n = 3 ;
  double t1 , t2 ;
  t1 = omp_get_wtime();
  #pragma omp parallel
  {
    int tid = omp_get_thread_num();
    #pragma omp for nowait
    for(i=0;i<n;i++)
      printf("Thread %d I : %d\n",tid,i);
    printf("Thread id %d with NO WAIT EFFECT\n",tid);
  }
  t2 = omp_get_wtime();
  printf("Time Taken : %lf \n",t2-t1);
}
