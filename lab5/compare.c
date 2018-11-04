#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(void){

	int i,N;
	N=500;
	srand(time(0));
	int arr[N];
	int chunk=50;

	for(i=0;i<N;i++)
		arr[i]=rand();

	printf("Sequential execution:\n\n");
    clock_t start, end;
     double cpu_time_used;
     
     start = clock(); 

	int min=INT_MAX;
	for(i=0;i<N;i++){
		if(arr[i]<min)
			min=arr[i];
	}

	end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("CPU Time : %lf",cpu_time_used);
	printf("\n \tMinimum in the array: %d\n\n",min);

	printf("Parallel execution:\n\n");
    // double cpu_time_used;
     
     start = clock(); 

	
	#pragma omp parallel shared(min,arr,chunk) private(i) num_threads(4)
	{
		
		int min=INT_MAX;
		#pragma omp for schedule(runtime)
		for(i=0;i<N;i++){
			if(arr[i]<min)
				min=arr[i];
		}
	}
	
end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("CPU Time : %lf",cpu_time_used);
	
	printf("\n \tMinimum in the array: %d\n\n",min);
}