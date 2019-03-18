#include<stdio.h>
#include<omp.h>
void main()
{
  int a[100];
  a[0] = 0 ;
  #pragma omp parallel for schedule(dynamic)
    for(int i= 1 ; i<100  ;i++)
      a[i] = a[i-1] + 1 ;
  printf("%d\n",a[99] );
}
