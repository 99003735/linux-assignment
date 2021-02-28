

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20

#define MAX_THREAD 5 


int a[] = { 1, 5, 10, 15, 20, 25, 30, 35, 125, 525, 625, 44, 38, 64, 110, 75 ,100,56, 40, 78,89}; 
int sum[5] = { 0 }; 
int part = 0; 

void* sum_array(void* arg) 
{ 

	int thread_part = part++; 

	for (int j = thread_part * (MAX / 5); j < (thread_part + 1) * (MAX / 5); j++) 
		sum[thread_part] += a[j]; 
} 

int main() 
{ 

	pthread_t threads[MAX_THREAD]; 

	
	for (int j = 0; j < MAX_THREAD; j++) 
		pthread_create(&threads[j], NULL, sum_array, (void*)NULL); 

	for (int j = 0; j < MAX_THREAD; j++) 
		pthread_join(threads[j], NULL); 
 
	int total_sum = 0; 
	for (int j = 0; j < MAX_THREAD; j++) 
		total_sum += sum[j]; 

    printf("Sum = : \n%d",total_sum);
	return 0; 
} 
