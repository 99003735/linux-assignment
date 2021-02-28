#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 


#define max 16 

// Max number of thread 
#define Th_max 4 

// Array 
int arr[max] = { 1, 5, 7, 10, 12, 54, 225, 258, 20, 
			22, 205, 27, 200, 84, 210, 220 }; 

// Array to store max of threads 
int max_num[Th_max] = { 0 }; 
int thread_no = 0; 

// Function to find maximum 
void maximum(void* arg) 
{ 
	int j, num = thread_no++; 
	int maxs = 0; 

	for (j = num * (max / 4); j < (num + 1) * (max / 4); j++) { 
		if (arr[j] > maxs) 
			maxs = arr[j]; 
	} 

	max_num[num] = maxs; 
} 

// Driver code 
int main() 
{ 
	int maxs = 0; 
	int j; 
	pthread_t threads[Th_max]; 

	// creating 4 threads 
	for (j = 0; j < Th_max; j++) 
		pthread_create(&threads[j], NULL, 
					maximum, (void*)NULL); 

	// joining 4 threads i.e. waiting for 
	// all 4 threads to complete 
	for (j = 0; j < Th_max; j++) 
		pthread_join(threads[j], NULL); 

	// Finding max element in an array 
	// by individual threads 
	for (j = 0; j < Th_max; j++) { 
		if (max_num[j] > maxs) 
			maxs = max_num[j]; 
	} 

	printf("Maximum num is : %d", maxs); 

	return 0; 
} 
