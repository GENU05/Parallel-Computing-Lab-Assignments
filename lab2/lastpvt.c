#include<stdio.h>
#include<omp.h>

int main()
{
  int x = 0 , i , n = 3 ;
  #pragma omp parallel
  {
    int tid = omp_get_thread_num();
    #pragma omp for lastprivate(i)
    for(i=0;i<n;i++)
    {
      printf("Thread %d :: Value i : %d\n",tid,i);
      x = x + i ;
      printf("Thread %d :: Value x : %d\n",tid,x);
    }
  }
  printf("X is : %d\n",x);
  printf("I is : %d\n",i);
}
