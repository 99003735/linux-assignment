#include <stdio.h> 
#include <time.h> 
int main() 
{ 
	time_t s, val = 1; 
	struct tm* time_is; 
	s = time(NULL); 
	time_is = localtime(&s); 

	
	printf("%02d:%02d:%02d", 
		time_is->tm_hour, 
		time_is->tm_min, 
		time_is->tm_sec); 

	return 0; 
} 

